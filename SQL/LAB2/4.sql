USE lab2;
SELECT S.Surname, M.Subject, M.Mark
FROM Student S 
JOIN Matks M ON S.idStudent = M.Student_idStudent;