USE labhoi4;

-- ТРИГГЕР 1: AFTER INSERT.
-- При создании страны добавляется идеалогия (Демократия на 50%)

DELIMITER //

CREATE TRIGGER after_country_insert
AFTER INSERT ON Country
FOR EACH ROW
BEGIN
    INSERT INTO CountryIdeology (IDCountry, IDSubject, SupportPercent)
    VALUES (NEW.IDCountry, 1, 50.00); 
END //

DELIMITER ;

-- Добавление новой страны (Швеция)
INSERT INTO Country (INN, NameCountry, IDGroup, SPassport, NPassport, DataPassport, NameDeptPassport, Sname, MarkAVG) 
VALUES ('SWE', 'Швеция', 4, 'Паспорт Швеции', '009', '1936-01-01', 'Социал-демократы', 'Ханссон', 60.00);

SELECT * FROM Country WHERE INN = 'SWE';

-- Проверка, что триггер автоматически создал связь
SELECT ci.*, c.NameCountry, i.NameSubject 
FROM CountryIdeology ci
JOIN Country c ON ci.IDCountry = c.IDCountry
JOIN Ideology i ON ci.IDSubject = i.IDSubject
WHERE c.INN = 'SWE';

-- ТРИГГЕР 2: BEFORE UPDATE.
-- При изменении типа войск в WarHistory автоматически меняется длительность битвы.

DELIMITER //

CREATE TRIGGER before_warhistory_update
BEFORE UPDATE ON WarHistory
FOR EACH ROW
BEGIN
    IF NEW.IDWork = 3 AND OLD.IDWork != 3 THEN
        SET NEW.CLOCK = NEW.CLOCK + 10;
    END IF;
END //

DELIMITER ;

-- Любая битва с участием пехоты
SELECT * FROM WarHistory WHERE IDWork = 1;

-- Обновления типа войск
UPDATE WarHistory 
SET IDWork = 3 
WHERE IDSubject = 2 AND NTerm = 1;

-- Проверка автоматически изменённого врмени
SELECT * FROM WarHistory WHERE IDSubject = 2 AND NTerm = 1;
