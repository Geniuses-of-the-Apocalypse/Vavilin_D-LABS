package main.guu.ru.lab11.controller;

import main.guu.ru.lab11.model.RailwayComposition;
import main.guu.ru.lab11.service.RailwayCompositionService;
import io.swagger.v3.oas.annotations.Operation;
import io.swagger.v3.oas.annotations.Parameter;
import io.swagger.v3.oas.annotations.responses.ApiResponse;
import io.swagger.v3.oas.annotations.responses.ApiResponses;
import io.swagger.v3.oas.annotations.tags.Tag;
import lombok.RequiredArgsConstructor;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/api/railway-compositions")
@RequiredArgsConstructor
@Tag(name = "Железнодорожные составы", description = "API для управления железнодорожными составами")
public class RailwayCompositionController {

    private final RailwayCompositionService service;

    @PostMapping
    @Operation(summary = "Добавить новый состав", description = "Создаёт новый железнодорожный состав в базе данных")
    @ApiResponses(value = {
            @ApiResponse(responseCode = "201", description = "Состав успешно создан"),
            @ApiResponse(responseCode = "400", description = "Некорректные данные"),
            @ApiResponse(responseCode = "409", description = "Состав с таким номером уже существует")
    })
    public ResponseEntity<RailwayComposition> addComposition(
            @Parameter(description = "Данные состава", required = true)
            @RequestBody RailwayComposition composition) {
        RailwayComposition created = service.addComposition(composition);
        return new ResponseEntity<>(created, HttpStatus.CREATED);
    }

    @GetMapping
    @Operation(summary = "Получить все составы", description = "Возвращает список всех железнодорожных составов")
    @ApiResponse(responseCode = "200", description = "Список успешно получен")
    public ResponseEntity<List<RailwayComposition>> getAllCompositions() {
        List<RailwayComposition> compositions = service.getAllCompositions();
        return ResponseEntity.ok(compositions);
    }

    @GetMapping("/{id}")
    @Operation(summary = "Получить состав по ID", description = "Возвращает состав по его уникальному идентификатору")
    @ApiResponses(value = {
            @ApiResponse(responseCode = "200", description = "Состав найден"),
            @ApiResponse(responseCode = "404", description = "Состав не найден")
    })
    public ResponseEntity<RailwayComposition> getCompositionById(
            @Parameter(description = "ID состава", required = true, example = "1")
            @PathVariable Long id) {
        return service.getCompositionById(id)
                .map(ResponseEntity::ok)
                .orElse(ResponseEntity.notFound().build());
    }

    @GetMapping("/train/{trainNumber}")
    @Operation(summary = "Получить состав по номеру поезда", description = "Возвращает состав по его номеру")
    @ApiResponses(value = {
            @ApiResponse(responseCode = "200", description = "Состав найден"),
            @ApiResponse(responseCode = "404", description = "Состав с таким номером не найден")
    })
    public ResponseEntity<RailwayComposition> getByTrainNumber(
            @Parameter(description = "Номер поезда", required = true, example = "101")
            @PathVariable String trainNumber) {
        return service.getCompositionByTrainNumber(trainNumber)
                .map(ResponseEntity::ok)
                .orElse(ResponseEntity.notFound().build());
    }

    @GetMapping("/status/{status}")
    @Operation(summary = "Получить составы по статусу", description = "Возвращает все составы с указанным статусом")
    @ApiResponse(responseCode = "200", description = "Список успешно получен")
    public ResponseEntity<List<RailwayComposition>> getByStatus(
            @Parameter(description = "Статус состава (FORMING, READY, DEPARTED, ARRIVED)", required = true, example = "READY")
            @PathVariable String status) {
        return ResponseEntity.ok(service.getCompositionsByStatus(status));
    }

    @GetMapping("/search")
    @Operation(summary = "Поиск составов по критериям", description = "Ищет составы по минимальному количеству вагонов и максимальному весу")
    @ApiResponse(responseCode = "200", description = "Результаты поиска")
    public ResponseEntity<List<RailwayComposition>> searchByCriteria(
            @Parameter(description = "Минимальное количество вагонов", example = "10")
            @RequestParam(required = false) Integer minCars,
            @Parameter(description = "Максимальный вес в тоннах", example = "1000.0")
            @RequestParam(required = false) Double maxWeight) {
        return ResponseEntity.ok(service.findCompositionsByCriteria(minCars, maxWeight));
    }

    @PutMapping("/{id}")
    @Operation(summary = "Обновить состав", description = "Обновляет данные существующего состава")
    @ApiResponses(value = {
            @ApiResponse(responseCode = "200", description = "Состав успешно обновлён"),
            @ApiResponse(responseCode = "404", description = "Состав не найден"),
            @ApiResponse(responseCode = "400", description = "Некорректные данные")
    })
    public ResponseEntity<RailwayComposition> updateComposition(
            @Parameter(description = "ID состава", required = true, example = "1")
            @PathVariable Long id,
            @Parameter(description = "Обновлённые данные состава", required = true)
            @RequestBody RailwayComposition composition) {
        composition.setId(id);
        RailwayComposition updated = service.updateComposition(composition);
        return ResponseEntity.ok(updated);
    }

    @DeleteMapping("/{id}")
    @Operation(summary = "Удалить состав по ID", description = "Удаляет состав по его идентификатору")
    @ApiResponses(value = {
            @ApiResponse(responseCode = "204", description = "Состав успешно удалён"),
            @ApiResponse(responseCode = "404", description = "Состав не найден")
    })
    public ResponseEntity<Void> deleteComposition(
            @Parameter(description = "ID состава для удаления", required = true, example = "1")
            @PathVariable Long id) {
        if (service.deleteComposition(id)) {
            return ResponseEntity.noContent().build();
        }
        return ResponseEntity.notFound().build();
    }

    @DeleteMapping("/train/{trainNumber}")
    @Operation(summary = "Удалить состав по номеру поезда", description = "Удаляет состав по его номеру")
    @ApiResponses(value = {
            @ApiResponse(responseCode = "204", description = "Состав успешно удалён"),
            @ApiResponse(responseCode = "404", description = "Состав не найден")
    })
    public ResponseEntity<Void> deleteByTrainNumber(
            @Parameter(description = "Номер поезда для удаления", required = true, example = "101")
            @PathVariable String trainNumber) {
        if (service.deleteCompositionByTrainNumber(trainNumber)) {
            return ResponseEntity.noContent().build();
        }
        return ResponseEntity.notFound().build();
    }
}