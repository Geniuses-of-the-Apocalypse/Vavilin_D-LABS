USE labhoi4;

START TRANSACTION;

-- Меняем должность
UPDATE Leader 
SET PostTeacher = '34-й Президент США' 
WHERE DEPTNAME = 'Дуайт Эйзенхауэр';

-- Добавляем новую страну (например, Испанию)
INSERT INTO Country (INN, NameCountry, IDGroup, Sname, MarkAVG) 
VALUES ('SPA', 'Испания', 4, 'Франко', 30.00);

SELECT DEPTNAME, PostTeacher FROM Leader WHERE DEPTNAME = 'Дуайт Эйзенхауэр';
SELECT NameCountry FROM Country WHERE INN = 'SPA';

COMMIT;

SELECT DEPTNAME, PostTeacher FROM Leader WHERE DEPTNAME = 'Дуайт Эйзенхауэр';
SELECT NameCountry FROM Country WHERE INN = 'SPA';
