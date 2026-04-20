package main.guu.ru.lab11;

import main.guu.ru.lab11.model.RailwayComposition;
import main.guu.ru.lab11.service.RailwayCompositionService;
import lombok.RequiredArgsConstructor;
import org.springframework.boot.CommandLineRunner;
import org.springframework.stereotype.Component;

import java.util.List;
import java.util.Scanner;

@Component
@RequiredArgsConstructor
public class ConsoleMenu implements CommandLineRunner {

    private final RailwayCompositionService service;
    private final Scanner scanner = new Scanner(System.in);

    @Override
    public void run(String... args) {
        printBanner();
        showMenu();
    }

    private void printBanner() {
        System.out.println("\n" +
                "╔══════════════════════════════════════════════════════════════╗\n" +
                "║         УПРАВЛЕНИЕ ЖЕЛЕЗНОДОРОЖНЫМИ СОСТАВАМИ                ║\n" +
                "║                      Интерактивная консоль                   ║\n" +
                "╚══════════════════════════════════════════════════════════════╝");
    }

    private void showMenu() {
        while (true) {
            System.out.println("\n >>МЕНЮ ОПЕРАЦИЙ:");
            System.out.println("┌─────────────────────────────────────────────┐");
            System.out.println("│ 1. ДОБАВИТЬ новый состав                    │");
            System.out.println("│ 2. ПОКАЗАТЬ все составы                     │");
            System.out.println("│ 3. НАЙТИ состав по номеру поезда            │");
            System.out.println("│ 4. ИЗМЕНИТЬ состав                          │");
            System.out.println("│ 5. УДАЛИТЬ состав по ID                     │");
            System.out.println("│ 6. УДАЛИТЬ состав по номеру поезда          │");
            System.out.println("│ 7. ПОИСК по статусу                         │");
            System.out.println("│ 8. ПОИСК по критериям (вагоны/вес)          │");
            System.out.println("│ 0. ВЫХОД                                    │");
            System.out.println("└─────────────────────────────────────────────┘");
            System.out.print("\n >Введите номер операции: ");

            int choice = getIntInput();
            switch (choice) {
                case 1 -> addComposition();
                case 2 -> showAllCompositions();
                case 3 -> findByTrainNumber();
                case 4 -> updateComposition();
                case 5 -> deleteById();
                case 6 -> deleteByTrainNumber();
                case 7 -> findByStatus();
                case 8 -> findByCriteria();
                case 0 -> {
                    System.out.println("\n До свидания!");
                    System.exit(0);
                }
                default -> System.out.println("Неверный ввод! Попробуйте снова.");
            }
        }
    }

    //Добавление состава
    private void addComposition() {
        System.out.println("\n━━━━━━ ДОБАВЛЕНИЕ НОВОГО СОСТАВА ━━━━━━");

        RailwayComposition comp = new RailwayComposition();

        System.out.print("Номер поезда: ");
        comp.setTrainNumber(scanner.nextLine());

        System.out.print("Название состава: ");
        comp.setCompositionName(scanner.nextLine());

        System.out.print("Количество вагонов: ");
        comp.setNumberOfCars(getIntInput());

        System.out.print("Общий вес (тонн): ");
        comp.setTotalWeight(getDoubleInput());

        System.out.print("Длина (метров): ");
        comp.setLength(getDoubleInput());

        System.out.print("Серия локомотива: ");
        comp.setLocomotiveSeries(scanner.nextLine());

        System.out.print("Пункт назначения: ");
        comp.setDestination(scanner.nextLine());

        System.out.print("Статус (FORMING/READY/DEPARTED/ARRIVED): ");
        comp.setStatus(scanner.nextLine().toUpperCase());

        try {
            RailwayComposition saved = service.addComposition(comp);
            System.out.println("\n СОСТАВ УСПЕШНО ДОБАВЛЕН!");
            System.out.println("   ID: " + saved.getId());
            System.out.println("   Номер: " + saved.getTrainNumber());
            System.out.println("   Название: " + saved.getCompositionName());
        } catch (Exception e) {
            System.out.println(" Ошибка: " + e.getMessage());
        }
    }

    //Показ всех составов
    private void showAllCompositions() {
        System.out.println("\n━━━━━━ ВСЕ ЖЕЛЕЗНОДОРОЖНЫЕ СОСТАВЫ ━━━━━━");
        List<RailwayComposition> compositions = service.getAllCompositions();

        if (compositions.isEmpty()) {
            System.out.println("Составов пока нет!");
            return;
        }

        System.out.printf("%-4s %-12s %-25s %-8s %-10s %-15s%n",
                "ID", "Номер", "Название", "Вагонов", "Вес(т)", "Статус");
        System.out.println("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");

        for (RailwayComposition comp : compositions) {
            System.out.printf("%-4d %-12s %-25s %-8d %-10.1f %-15s%n",
                    comp.getId(),
                    comp.getTrainNumber(),
                    truncate(comp.getCompositionName(), 25),
                    comp.getNumberOfCars(),
                    comp.getTotalWeight(),
                    comp.getStatus());
        }
        System.out.println("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" +
                "");
        System.out.println(" Всего составов: " + compositions.size());
    }

    //Поиск по номеру поезда
    private void findByTrainNumber() {
        System.out.println("\n━━━━━━ ПОИСК ПО НОМЕРУ ПОЕЗДА ━━━━━━");
        System.out.print("Введите номер поезда: ");
        String trainNumber = scanner.nextLine();

        service.getCompositionByTrainNumber(trainNumber).ifPresentOrElse(
                comp -> {
                    System.out.println("\n СОСТАВ НАЙДЕН:");
                    printCompositionDetails(comp);
                },
                () -> System.out.println(" Состав с номером '" + trainNumber + "' не найден!")
        );
    }

    //Изменить инфу о составе
    private void updateComposition() {
        System.out.println("\n━━━━━━ ИЗМЕНЕНИЕ СОСТАВА ━━━━━━");
        System.out.print("Введите ID состава для изменения: ");
        Long id = (long) getIntInput();

        service.getCompositionById(id).ifPresentOrElse(
                existing -> {
                    System.out.println("\nТекущие данные:");
                    printCompositionDetails(existing);

                    System.out.println("\nВведите новые данные (оставьте пустым, чтобы не менять):");

                    System.out.print("Новый номер поезда [" + existing.getTrainNumber() + "]: ");
                    String input = scanner.nextLine();
                    if (!input.isEmpty()) existing.setTrainNumber(input);

                    System.out.print("Новое название [" + existing.getCompositionName() + "]: ");
                    input = scanner.nextLine();
                    if (!input.isEmpty()) existing.setCompositionName(input);

                    System.out.print("Новое количество вагонов [" + existing.getNumberOfCars() + "]: ");
                    input = scanner.nextLine();
                    if (!input.isEmpty()) existing.setNumberOfCars(Integer.parseInt(input));

                    System.out.print("Новый вес [" + existing.getTotalWeight() + "]: ");
                    input = scanner.nextLine();
                    if (!input.isEmpty()) existing.setTotalWeight(Double.parseDouble(input));

                    System.out.print("Новый статус [" + existing.getStatus() + "]: ");
                    input = scanner.nextLine();
                    if (!input.isEmpty()) existing.setStatus(input.toUpperCase());

                    service.updateComposition(existing);
                    System.out.println("\n СОСТАВ УСПЕШНО ОБНОВЛЕН!");
                },
                () -> System.out.println(" Состав с ID " + id + " не найден!")
        );
    }

    //Удаление по ID
    private void deleteById() {
        System.out.println("\n━━━━━━ УДАЛЕНИЕ СОСТАВА ПО ID ━━━━━━");
        System.out.print("Введите ID состава для удаления: ");
        int id = getIntInput();

        System.out.print("Вы уверены? (y/n): ");
        if (scanner.nextLine().equalsIgnoreCase("y")) {
            if (service.deleteComposition((long) id)) {
                System.out.println(" Состав с ID " + id + " удален!");
            } else {
                System.out.println(" Состав с ID " + id + " не найден!");
            }
        } else {
            System.out.println(" Удаление отменено");
        }
    }

    //Удаление по номеру поезда
    private void deleteByTrainNumber() {
        System.out.println("\n━━━━━━ УДАЛЕНИЕ ПО НОМЕРУ ПОЕЗДА ━━━━━━");
        System.out.print("Введите номер поезда для удаления: ");
        String trainNumber = scanner.nextLine();

        System.out.print("Вы уверены? (y/n): ");
        if (scanner.nextLine().equalsIgnoreCase("y")) {
            if (service.deleteCompositionByTrainNumber(trainNumber)) {
                System.out.println(" Состав с номером '" + trainNumber + "' удален!");
            } else {
                System.out.println(" Состав с номером '" + trainNumber + "' не найден!");
            }
        } else {
            System.out.println(" Удаление отменено");
        }
    }

    //Поиск по статусу
    private void findByStatus() {
        System.out.println("\n━━━━━━ ПОИСК ПО СТАТУСУ ━━━━━━");
        System.out.print("Введите статус (FORMING/READY/DEPARTED/ARRIVED): ");
        String status = scanner.nextLine().toUpperCase();

        List<RailwayComposition> compositions = service.getCompositionsByStatus(status);

        if (compositions.isEmpty()) {
            System.out.println(" Составов со статусом '" + status + "' не найдено!");
            return;
        }

        System.out.println("\n НАЙДЕНО " + compositions.size() + " СОСТАВОВ:");
        for (RailwayComposition comp : compositions) {
            System.out.printf("   • %s - %s (%d вагонов)%n",
                    comp.getTrainNumber(),
                    comp.getCompositionName(),
                    comp.getNumberOfCars());
        }
    }

    //Поиск по критериям
    private void findByCriteria() {
        System.out.println("\n━━━━━━ ПОИСК ПО КРИТЕРИЯМ ━━━━━━");
        System.out.print("Минимальное количество вагонов (Enter - пропустить): ");
        String input = scanner.nextLine();
        Integer minCars = input.isEmpty() ? null : Integer.parseInt(input);

        System.out.print("Максимальный вес (Enter - пропустить): ");
        input = scanner.nextLine();
        Double maxWeight = input.isEmpty() ? null : Double.parseDouble(input);

        List<RailwayComposition> compositions = service.findCompositionsByCriteria(minCars, maxWeight);

        if (compositions.isEmpty()) {
            System.out.println(" Составов по заданным критериям не найдено!");
            return;
        }

        System.out.println("\n НАЙДЕНО " + compositions.size() + " СОСТАВОВ:");
        for (RailwayComposition comp : compositions) {
            System.out.printf("   • %s - %s (%d вагонов, %.1f т)%n",
                    comp.getTrainNumber(),
                    comp.getCompositionName(),
                    comp.getNumberOfCars(),
                    comp.getTotalWeight());
        }
    }

    //Вспомогательные методы
    private void printCompositionDetails(RailwayComposition comp) {
        System.out.println("┌─────────────────────────────────────────");
        System.out.println("│ ID: " + comp.getId());
        System.out.println("│ Номер поезда: " + comp.getTrainNumber());
        System.out.println("│ Название: " + comp.getCompositionName());
        System.out.println("│ Вагонов: " + comp.getNumberOfCars());
        System.out.println("│ Вес: " + comp.getTotalWeight() + " т");
        System.out.println("│ Длина: " + comp.getLength() + " м");
        System.out.println("│ Локомотив: " + comp.getLocomotiveSeries());
        System.out.println("│ Назначение: " + comp.getDestination());
        System.out.println("│ Статус: " + comp.getStatus());
        System.out.println("│ Создан: " + comp.getCreatedAt());
        System.out.println("└─────────────────────────────────────────");
    }

    private int getIntInput() {
        while (true) {
            try {
                return Integer.parseInt(scanner.nextLine());
            } catch (NumberFormatException e) {
                System.out.print(" Введите число: ");
            }
        }
    }

    private double getDoubleInput() {
        while (true) {
            try {
                return Double.parseDouble(scanner.nextLine());
            } catch (NumberFormatException e) {
                System.out.print(" Введите число: ");
            }
        }
    }

    private String truncate(String str, int length) {
        if (str == null) return "";
        return str.length() > length ? str.substring(0, length - 3) + "..." : str;
    }
}