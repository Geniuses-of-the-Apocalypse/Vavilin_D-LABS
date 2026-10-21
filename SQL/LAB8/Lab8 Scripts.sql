Use lab8sql;

-- Создание таблицы АБИТУРИЕНТЫ
CREATE TABLE Abiturients (
    Number INT AUTO_INCREMENT PRIMARY KEY NOT NULL, 
    SurName VARCHAR(20) NOT NULL,                  
    Name VARCHAR(15) NOT NULL,                      
    FamilName VARCHAR(15),                          
    Attestat_Number VARCHAR(10),                   
    Attestat_Data DATE                             
);

-- Создание таблицы ЭКЗАМЕНЫ
CREATE TABLE Exams (
    Exam_code INT AUTO_INCREMENT PRIMARY KEY NOT NULL, 
    Subject VARCHAR(30),                                  
    Exam_data DATE NOT NULL,                          
    Exam_type VARCHAR(30),                             
    Facultet VARCHAR(5)                                  
);

-- Создание таблицы ОЦЕНКИ
CREATE TABLE Marks (
    Exam_code INT NOT NULL,                      
    Abiturient_number INT NOT NULL,    
    Marks DECIMAL(2, 1) CHECK (Marks >= 2 AND Marks <= 5), 
    
    INDEX idx_Exam_code (Exam_code),
    INDEX idx_Abiturient_number (Abiturient_number) 
);
