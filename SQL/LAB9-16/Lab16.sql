USE labHOI4;

DELIMITER //

CREATE PROCEDURE SimulateWar(IN p_days INT, IN p_leader_id INT)
BEGIN
    -- Объявляем переменные
    DECLARE v_day INT DEFAULT 1;
    DECLARE v_current_clock INT;
    DECLARE v_leader_name VARCHAR(100);

    -- Находим текущее значение CLOCK и имя генерала
    SELECT CLOCK, DEPTNAME INTO v_current_clock, v_leader_name 
    FROM WarHistory 
    JOIN Leader ON WarHistory.PIN = Leader.PIN 
    WHERE WarHistory.PIN = p_leader_id 
    LIMIT 1;

    IF v_current_clock IS NULL THEN
        SELECT 'Генерал не найден или не участвует в битвах' AS ErrorMessage;
    ELSE
        WHILE v_day <= p_days DO
            SET v_current_clock = v_current_clock + 1;
	
            SELECT 
                v_day AS День_симуляции, 
                v_leader_name AS Генерал, 
                v_current_clock AS Общая_длительность;
            
            SET v_day = v_day + 1;
        END WHILE;

        UPDATE WarHistory 
        SET CLOCK = v_current_clock 
        WHERE PIN = p_leader_id;
    END IF;
END //

DELIMITER ;

CALL SimulateWar(3, 6);