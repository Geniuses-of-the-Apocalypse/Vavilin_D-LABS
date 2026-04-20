package main.guu.ru.lab11.mapper;

import main.guu.ru.lab11.model.RailwayComposition;
import org.apache.ibatis.annotations.*;

import java.util.List;
import java.util.Optional;

@Mapper
public interface RailwayCompositionMapper {

    //Создание
    @Insert("INSERT INTO жд_составы (train_number, composition_name, number_of_cars, " +
            "total_weight, length, locomotive_series, destination, departure_time, status) " +
            "VALUES (#{trainNumber}, #{compositionName}, #{numberOfCars}, #{totalWeight}, " +
            "#{length}, #{locomotiveSeries}, #{destination}, #{departureTime}, #{status})")
    @Options(useGeneratedKeys = true, keyProperty = "id")
    int insert(RailwayComposition composition);

    //Чтение по ID
    @Select("SELECT * FROM жд_составы WHERE id = #{id}")
    @Results(id = "compositionResult", value = {
            @Result(property = "id", column = "id"),
            @Result(property = "trainNumber", column = "train_number"),
            @Result(property = "compositionName", column = "composition_name"),
            @Result(property = "numberOfCars", column = "number_of_cars"),
            @Result(property = "totalWeight", column = "total_weight"),
            @Result(property = "locomotiveSeries", column = "locomotive_series"),
            @Result(property = "departureTime", column = "departure_time"),
            @Result(property = "createdAt", column = "created_at")
    })
    Optional<RailwayComposition> findById(Long id);

    //Чтение всех сущих файлов
    @Select("SELECT * FROM жд_составы ORDER BY id DESC")
    @ResultMap("compositionResult")
    List<RailwayComposition> findAll();

    //Чтение - поиск по номеру поезда
    @Select("SELECT * FROM жд_составы WHERE train_number = #{trainNumber}")
    @ResultMap("compositionResult")
    Optional<RailwayComposition> findByTrainNumber(String trainNumber);

    //Чтение - поиск по статусу
    @Select("SELECT * FROM жд_составы WHERE status = #{status}")
    @ResultMap("compositionResult")
    List<RailwayComposition> findByStatus(String status);

    //Замена
    @Update("UPDATE жд_составы SET train_number = #{trainNumber}, " +
            "composition_name = #{compositionName}, number_of_cars = #{numberOfCars}, " +
            "total_weight = #{totalWeight}, length = #{length}, " +
            "locomotive_series = #{locomotiveSeries}, destination = #{destination}, " +
            "departure_time = #{departureTime}, status = #{status} " +
            "WHERE id = #{id}")
    int update(RailwayComposition composition);

    //Удаление по номеру ID
    @Delete("DELETE FROM жд_составы WHERE id = #{id}")
    int deleteById(Long id);

    //Удаление по номеру поезда
    @Delete("DELETE FROM жд_составы WHERE train_number = #{trainNumber}")
    int deleteByTrainNumber(String trainNumber);

    //Запрос с параметром
    @Select("SELECT * FROM жд_составы WHERE number_of_cars >= #{minCars} AND total_weight <= #{maxWeight}")
    @ResultMap("compositionResult")
    List<RailwayComposition> findByCriteria(@Param("minCars") Integer minCars,
                                            @Param("maxWeight") Double maxWeight);
}