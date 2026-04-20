//
//package main.guu.ru.lab11;
//
//import main.guu.ru.lab11.model.RailwayComposition;
//import main.guu.ru.lab11.service.RailwayCompositionService;
//import lombok.RequiredArgsConstructor;
//import lombok.extern.slf4j.Slf4j;
//import org.springframework.boot.CommandLineRunner;
//import org.springframework.stereotype.Component;
//
//import java.time.LocalDateTime;
//import java.util.List;
//
//@Slf4j
//@Component
//@RequiredArgsConstructor
//public class DemoRunner implements CommandLineRunner {
//
//    private final RailwayCompositionService service;
//
//    @Override
//    public void run(String... args) {
//        log.info("\n========== ДЕМОНСТРАЦИЯ РАБОТЫ С БД ==========\n");
//
//        // 1. Добавление составов
//        log.info("1. ДОБАВЛЕНИЕ составов:");
//        RailwayComposition comp1 = createComposition("101", "Express", 12, 680.5, 300.0,
//                "CHS200", "Kazan", "READY");
//        RailwayComposition comp2 = createComposition("102", "Tovaniy", 50, 3500.0, 720.0,
//                "VL85", "Ekaterininburg", "FORMING");
//
//        service.addComposition(comp1);
//        service.addComposition(comp2);
//        log.info("Добавлены составы: {} и {}", comp1.getTrainNumber(), comp2.getTrainNumber());
//
//        // 2. Получение всех составов
//        log.info("\n2. ВЫБОРКА всех составов:");
//        List<RailwayComposition> all = service.getAllCompositions();
//        all.forEach(comp -> log.info("   - {}: {} (статус: {})",
//                comp.getTrainNumber(), comp.getCompositionName(), comp.getStatus()));
//
//        // 3. Поиск по номеру поезда
//        log.info("\n3. ПОИСК по номеру поезда '101':");
//        service.getCompositionByTrainNumber("101").ifPresent(comp ->
//                log.info("   Найден: {} - {} вагонов", comp.getTrainNumber(), comp.getNumberOfCars()));
//
//        // 4. Поиск по статусу
//        log.info("\n4. ПОИСК по статусу 'READY':");
//        List<RailwayComposition> ready = service.getCompositionsByStatus("READY");
//        ready.forEach(comp -> log.info("   {} готов к отправлению", comp.getTrainNumber()));
//
//        // 5. Изменение состава
//        log.info("\n5. ИЗМЕНЕНИЕ состава '101':");
//        comp1.setNumberOfCars(15);
//        comp1.setStatus("DEPARTED");
//        service.updateComposition(comp1);
//        log.info("   ✓ Состав {} обновлен: {} вагонов, статус {}",
//                comp1.getTrainNumber(), comp1.getNumberOfCars(), comp1.getStatus());
//
//        // 6. Поиск по критериям
//        log.info("\n6. ПОИСК составов с >20 вагонов:");
//        List<RailwayComposition> heavy = service.findCompositionsByCriteria(20, null);
//        heavy.forEach(comp -> log.info("   {}: {} вагонов", comp.getTrainNumber(), comp.getNumberOfCars()));
//
//        // 7. Удаление состава
//        log.info("\n7. УДАЛЕНИЕ состава '102':");
//        service.deleteCompositionByTrainNumber("102");
//        log.info("   ✓ Состав 102 удален");
//
//        // 8. Финальная выборка
//        log.info("\n8. ФИНАЛЬНАЯ ВЫБОРКА (после удаления):");
//        service.getAllCompositions().forEach(comp ->
//                log.info("   Остался состав: {} - {}", comp.getTrainNumber(), comp.getCompositionName()));
//
//        log.info("\n========== ДЕМОНСТРАЦИЯ ЗАВЕРШЕНА ==========\n");
//    }
//
//    private RailwayComposition createComposition(String trainNumber, String name, int cars,
//                                                 double weight, double length, String locomotive,
//                                                 String destination, String status) {
//        RailwayComposition comp = new RailwayComposition();
//        comp.setTrainNumber(trainNumber);
//        comp.setCompositionName(name);
//        comp.setNumberOfCars(cars);
//        comp.setTotalWeight(weight);
//        comp.setLength(length);
//        comp.setLocomotiveSeries(locomotive);
//        comp.setDestination(destination);
//        comp.setDepartureTime(LocalDateTime.now().plusDays(1));
//        comp.setStatus(status);
//        return comp;
//    }
//}