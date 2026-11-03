USE labhoi4;

SELECT DEPTNAME, PostTeacher, TName FROM Leader WHERE DEPTNAME = 'Георгий Жуков';

START TRANSACTION;

UPDATE Leader 
SET PostTeacher = 'Генералиссимус', 
    TName = 'Победитель' 
WHERE DEPTNAME = 'Георгий Жуков';

-- Проверяем, что изменения применились внутри транзакции
SELECT DEPTNAME, PostTeacher, TName FROM Leader WHERE DEPTNAME = 'Георгий Жуков';

ROLLBACK;

SELECT DEPTNAME, PostTeacher, TName FROM Leader WHERE DEPTNAME = 'Георгий Жуков';
