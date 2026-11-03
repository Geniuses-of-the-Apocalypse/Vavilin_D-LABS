USE labhoi4;

-- 1. INSERT
INSERT INTO Country (INN, NameCountry, IDGroup, Sname, MarkAVG) 
VALUES ('HUN', 'Венгрия', 1, 'Хорти', 45.00);

INSERT INTO Country (INN, NameCountry, IDGroup, Sname, MarkAVG)
VALUES ('BEL', 'Бельгия', 2, 'Леопольд III', 45.00);

-- 2. UPDATE
UPDATE Leader 
SET PostTeacher = 'Верховный главнокомандующий' 
WHERE DEPTNAME = 'Иосиф Сталин';

-- 3. DELETE
DELETE FROM Country
WHERE INN = 'BEL';
