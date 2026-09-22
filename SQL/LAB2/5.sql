USE lab2;
SELECT Surname, Name, Mark
FROM Student S
JOIN Matks N ON idStudent = Student_idStudent
WHERE Subject = 'Math' AND Mark = 2;