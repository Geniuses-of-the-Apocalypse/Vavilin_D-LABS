USE lab2;
SELECT Surname, Tel
FROM Student
WHERE Tel REGEXP '^[2-7]+$';