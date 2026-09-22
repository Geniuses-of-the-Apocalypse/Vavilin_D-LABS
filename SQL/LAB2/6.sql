USE lab2;
SELECT CONCAT(Surname, ' ', LEFT(Name, 1)) AS Surname_Initial
FROM Student
WHERE Surname LIKE 'u%' AND Surname LIKE '%v%';