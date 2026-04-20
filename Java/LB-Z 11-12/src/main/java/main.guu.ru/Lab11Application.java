package main.guu.ru.lab11;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
public class Lab11Application
{
    public static void main(String[] args) {
        SpringApplication.run(Lab11Application.class, args);
    }
}

//docker exec PostgresDB psql -U postgres -d postgres -c "TRUNCATE TABLE жд_составы RESTART IDENTITY; SELECT 'База данных очищена!' as Status;"


//КОМАНДЫ ДЛЯ КОНСОЛИ ИЛИ ДЛЯ БРАУЗЕРА:
//
//        1) Браузерный вывод:
//Swagger UI: http://localhost:8080/swagger-ui.html
//OpenAPI JSON: http://localhost:8080/api-docs
//
//        - http://localhost:8080/api/railway-compositions
//
//        - http://localhost:8080/api/railway-compositions/1
//
//        - http://localhost:8080/api/railway-compositions/search?name=Моск
//
//        2) Консольные командочки:
//
//        - 1. ПОКАЗАТЬ ВСЕ записи
//curl http://localhost:8080/api/railway-compositions
//
//        - 2. ПОКАЗАТЬ запись по ID
//curl http://localhost:8080/api/railway-compositions/1
//
//        - 3. ДОБАВИТЬ новую запись
//curl -X POST http://localhost:8080/api/railway-compositions-H "Content-Type: application/json" -d "{\"trainNumber\":\"101\","\compositionName\":\"Lastochka\",\"numberOfCars\":9,\"totalWeight\":70, \"length\":95,\"locomotiveSeries\": \"L15\",\"destination\":\"Moscow\",\"departureTime\":null,\"status\":\"READY\",\"createdAt\":\"2026-04-19T00:28:47\"}"
//
//        - 4. ИЗМЕНИТЬ запись
//curl -X PUT http://localhost:8080/api/railway-compositions/7 -H "Content-Type: application/json" -d "{\"trainNumber\":\"101\","\compositionName\":\"Lastochka\",\"numberOfCars\":9,\"totalWeight\":70, \"length\":95,\"locomotiveSeries\": \"L15\",\"destination\":\"Moscow\",\"departureTime\":null,\"status\":\"READY\",\"createdAt\":\"2026-04-19T00:28:47\"}"
//
//        - 5. УДАЛИТЬ запись
//curl -X DELETE http://localhost:8080/api/railway-compositions/7
//
//        - 6. ПОИСК по имени
//curl "http://localhost:8080/api/railway-compositions/search?name=Моск"
//
//        - 7. ФИЛЬТР по типу
//curl "http://localhost:8080/api/railway-compositions/type/город"
//
//        - 8. КОЛИЧЕСТВО записей
//curl "http://localhost:8080/api/railway-compositions/count"
//
//        3) PowerShell:
//
//        - 1. ПОКАЗАТЬ ВСЕ записи
//Invoke-WebRequest -Uri "http://localhost:8080/api/railway-compositions" -Method GET | Select-Object -ExpandProperty Content
//
// - 2. ПОКАЗАТЬ запись по ID
//Invoke-WebRequest -Uri "http://localhost:8080/api/nrailway-compositions/1" -Method GET | Select-Object -ExpandProperty Content
//
// - 3. ДОБАВИТЬ новую запись
//Invoke-WebRequest -Uri "http://localhost:8080/api/nrailway-compositions" -Method POST -ContentType "application/json" -Body '{"trainNumber":"101","compositionName":"Lastochka","numberOfCars":9,"totalWeight":70, "length":95, "locomotiveSeries": "L15", "destination": "Moscow", "departureTime":null, "status": "READY", "createdAt": "2026-04-19T00:28:47"}' | Select-Object -ExpandProperty Content
//
// - 4. ИЗМЕНИТЬ запись
//Invoke-WebRequest -Uri "http://localhost:8080/api/railway-compositions/7" -Method PUT -ContentType "application/json" -Body '{"trainNumber":"101","compositionName":"Lastochka","numberOfCars":9,"totalWeight":70, "length":95, "locomotiveSeries": "L15", "destination": "Moscow", "departureTime":null, "status": "READY", "createdAt": "2026-04-19T00:28:47"}' | Select-Object -ExpandProperty Content
//
// - 5. УДАЛИТЬ запись
//Invoke-WebRequest -Uri "http://localhost:8080/api/railway-compositions/7" -Method DELETE
//
// - 6. ПОИСК по имени
//Invoke-WebRequest -Uri "http://localhost:8080/api/railway-compositions/search?name=Моск" -Method GET | Select-Object -ExpandProperty Content
//
// - 8. КОЛИЧЕСТВО записей
//Invoke-WebRequest -Uri "http://localhost:8080/api/railway-compositions/count" -Method GET | Select-Object -ExpandProperty Content2