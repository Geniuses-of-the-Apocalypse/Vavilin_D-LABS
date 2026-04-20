package main.guu.ru.lab11.service;

import main.guu.ru.lab11.mapper.RailwayCompositionMapper;
import main.guu.ru.lab11.model.RailwayComposition;
import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;
import java.util.Optional;

@Slf4j
@Service
@RequiredArgsConstructor
@Transactional
public class RailwayCompositionService {

    private final RailwayCompositionMapper compositionMapper;

    // Добавление состава
    public RailwayComposition addComposition(RailwayComposition composition) {
        log.info("Adding new railway composition: {}", composition.getTrainNumber());
        int rows = compositionMapper.insert(composition);
        if (rows > 0) {
            log.info("Successfully added composition with ID: {}", composition.getId());
            return composition;
        }
        throw new RuntimeException("Failed to add composition");
    }

    // Получение всех составов
    @Transactional(readOnly = true)
    public List<RailwayComposition> getAllCompositions() {
        log.info("Fetching all railway compositions");
        return compositionMapper.findAll();
    }

    // Получение состава по ID
    @Transactional(readOnly = true)
    public Optional<RailwayComposition> getCompositionById(Long id) {
        log.info("Fetching composition by ID: {}", id);
        return compositionMapper.findById(id);
    }

    // Получение по номеру поезда
    @Transactional(readOnly = true)
    public Optional<RailwayComposition> getCompositionByTrainNumber(String trainNumber) {
        log.info("Fetching composition by train number: {}", trainNumber);
        return compositionMapper.findByTrainNumber(trainNumber);
    }

    // Обновление состава
    public RailwayComposition updateComposition(RailwayComposition composition) {
        log.info("Updating composition with ID: {}", composition.getId());
        int rows = compositionMapper.update(composition);
        if (rows > 0) {
            log.info("Successfully updated composition with ID: {}", composition.getId());
            return composition;
        }
        throw new RuntimeException("Composition not found with ID: " + composition.getId());
    }

    // Удаление состава по ID
    public boolean deleteComposition(Long id) {
        log.info("Deleting composition with ID: {}", id);
        int rows = compositionMapper.deleteById(id);
        if (rows > 0) {
            log.info("Successfully deleted composition with ID: {}", id);
            return true;
        }
        log.warn("Composition not found with ID: {}", id);
        return false;
    }

    // Удаление по номеру поезда
    public boolean deleteCompositionByTrainNumber(String trainNumber) {
        log.info("Deleting composition by train number: {}", trainNumber);
        int rows = compositionMapper.deleteByTrainNumber(trainNumber);
        return rows > 0;
    }

    // Поиск по статусу
    @Transactional(readOnly = true)
    public List<RailwayComposition> getCompositionsByStatus(String status) {
        log.info("Fetching compositions by status: {}", status);
        return compositionMapper.findByStatus(status);
    }

    // Поиск по критериям
    @Transactional(readOnly = true)
    public List<RailwayComposition> findCompositionsByCriteria(Integer minCars, Double maxWeight) {
        log.info("Searching compositions with min cars: {} and max weight: {}", minCars, maxWeight);
        return compositionMapper.findByCriteria(minCars, maxWeight);
    }
}