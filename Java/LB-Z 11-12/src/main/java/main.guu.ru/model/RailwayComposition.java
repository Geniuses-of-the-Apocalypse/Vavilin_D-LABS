package main.guu.ru.lab11.model;

import io.swagger.v3.oas.annotations.media.Schema;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import java.time.LocalDateTime;

@Data
@NoArgsConstructor
@AllArgsConstructor
@Schema(description = "Сущность железнодорожного состава")
public class RailwayComposition
{

    @Schema(description = "Уникальный идентификатор", example = "1", accessMode = Schema.AccessMode.READ_ONLY)
    private Long id;

    @Schema(description = "Номер поезда", example = "101A", requiredMode = Schema.RequiredMode.REQUIRED)
    private String trainNumber;

    @Schema(description = "Название состава", example = "Скорый поезд Москва-СПБ", requiredMode = Schema.RequiredMode.REQUIRED)
    private String compositionName;

    @Schema(description = "Количество вагонов", example = "15", minimum = "1")
    private Integer numberOfCars;

    @Schema(description = "Общий вес в тоннах", example = "850.5", minimum = "0")
    private Double totalWeight;

    @Schema(description = "Длина состава в метрах", example = "375.0", minimum = "0")
    private Double length;

    @Schema(description = "Серия локомотива", example = "ЭП20")
    private String locomotiveSeries;

    @Schema(description = "Пункт назначения", example = "Санкт-Петербург")
    private String destination;

    @Schema(description = "Время отправления", example = "2024-01-15T08:30:00")
    private LocalDateTime departureTime;

    @Schema(description = "Статус состава", example = "READY",
            allowableValues = {"FORMING", "READY", "DEPARTED", "ARRIVED"})
    private String status;

    @Schema(description = "Дата создания записи", accessMode = Schema.AccessMode.READ_ONLY)
    private LocalDateTime createdAt;
}