USE LabHOI4;

-- (1) Ограничение на столбец MarkAVG в таблице Country
ALTER TABLE Country 
ADD CONSTRAINT CheckCountryMarkAVG CHECK (MarkAVG >= 0);

-- (2) Связь таблицы WarHistory с таблицей Leader
ALTER TABLE WarHistory 
ADD CONSTRAINT FK_War_Leader FOREIGN KEY (PIN) REFERENCES Leader(PIN) ON DELETE CASCADE;

-- (3) Временно убираем связь между WarHistory и Leader
ALTER TABLE WarHistory 
DROP CONSTRAINT FK_War_Leader;

-- (4) Добавление связи между Country и Fraction
ALTER TABLE Country 
ADD CONSTRAINT FK_Country_Faction_New 
FOREIGN KEY (IDGroup) REFERENCES Fraction (IDFraction);

-- (5) Добавление в Leader столбец Loyalty
ALTER TABLE Leader 
ADD Loyalty INT DEFAULT 100;

-- (6) Увеличение VARCHAR параметра в таблице Report
ALTER TABLE Report 
MODIFY COLUMN NameReport VARCHAR(255);

-- (7)  Уменьшение размера поля NameCountry 
ALTER TABLE Country 
MODIFY COLUMN NameCountry VARCHAR(20);

-- (8) Добавление TechID  в таблицу Progress
ALTER TABLE Progress 
MODIFY COLUMN NRecordBook INT NOT NULL,  
DROP PRIMARY KEY,                        
ADD COLUMN TechID INT NOT NULL AUTO_INCREMENT PRIMARY KEY; 

-- (9) Удаление TName
ALTER TABLE Leader 
DROP COLUMN TName;

-- (10) Удаление связи и самой таблицы
ALTER TABLE Progress DROP CONSTRAINT progress_ibfk_3; 
DROP TABLE Report;
