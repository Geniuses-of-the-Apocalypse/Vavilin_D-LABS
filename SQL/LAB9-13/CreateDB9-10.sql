CREATE DATABASE LabHOI4;
USE LabHOI4;

-- Группировка стран
CREATE TABLE Fraction (
    IDFraction INT PRIMARY KEY AUTO_INCREMENT,
    NameFraction VARCHAR(100) NOT NULL -- Название фракции
);

-- Игрок или ИИ
CREATE TABLE Country (
    IDCountry INT PRIMARY KEY AUTO_INCREMENT,
    INN VARCHAR(20), -- Код страны
    NameCountry VARCHAR(100) NOT NULL, -- Название страны
    IDGroup INT, -- Ссылка на фракцию
    SPassport VARCHAR(50), -- Условный паспорт
    NPassport VARCHAR(50), -- Номер паспорта
    DataPassport DATE, -- Дата начала игры
    NameDeptPassport VARCHAR(100), -- Правящая партия
    Sname VARCHAR(100), -- Фамилия правителя
    MarkAVG DECIMAL(10,2), -- Рейтинг
    FOREIGN KEY (IDGroup) REFERENCES Fraction(IDFraction)
);

-- Идеалогии
CREATE TABLE Ideology (
    IDSubject INT PRIMARY KEY AUTO_INCREMENT,
    NameSubject VARCHAR(100) NOT NULL -- Название идеологии
);

-- Лидеры
CREATE TABLE Leader (
    PIN INT PRIMARY KEY AUTO_INCREMENT, -- ID лидера
    DEPTNAME VARCHAR(100) NOT NULL, -- Имя лидера
    PostTeacher VARCHAR(100), -- Должность
    DataHire DATE, -- Дата найма/прихода к власти
    TName VARCHAR(100) -- Титул
);

-- Достижения стрраны
CREATE TABLE Report (
    IDReport INT PRIMARY KEY AUTO_INCREMENT,
    NameReport VARCHAR(100) NOT NULL -- Название
);

-- Технологии и прогресс
CREATE TABLE Progress (
    NRecordBook INT PRIMARY KEY AUTO_INCREMENT,
    PIN INT, -- Ссылка на лидера, который проводил исследование
    IDSubject INT, -- Ссылка на идеологию
    IDReport INT, -- Ссылка на категорию
    NTerm INT, -- Уровень технологий
    Mark INT, -- Уровень прогресса
    FOREIGN KEY (PIN) REFERENCES Leader(PIN),
    FOREIGN KEY (IDSubject) REFERENCES Ideology(IDSubject),
    FOREIGN KEY (IDReport) REFERENCES Report(IDReport)
);

-- Типы войск
CREATE TABLE UnitType (
    IDWork INT PRIMARY KEY AUTO_INCREMENT,
    NameWork VARCHAR(100) NOT NULL -- Название типа войск
);

-- История
CREATE TABLE WarHistory (
    IDSubject INT, -- Ссылка на идеологию
    NTerm INT, -- Номер битвы/года
    IDWork INT, -- Тип войск, участвовавших в битве
    IDGROUP INT, -- Ссылка на фракцию
    PIN INT, -- Ссылка на генерала
    CLOCK INT, -- Длительность битвы
    PRIMARY KEY (IDSubject, NTerm), -- Композитный ключ
    FOREIGN KEY (IDWork) REFERENCES UnitType(IDWork),
    FOREIGN KEY (IDGROUP) REFERENCES Fraction(IDFraction),
    FOREIGN KEY (PIN) REFERENCES Leader(PIN)
);

-- Связь страны и идеалогии
CREATE TABLE CountryIdeology (
    IDCountry INT,
    IDSubject INT,
    SupportPercent DECIMAL(5,2), -- Поддержка идеалогии
    PRIMARY KEY (IDCountry, IDSubject),
    FOREIGN KEY (IDCountry) REFERENCES Country(IDCountry),
    FOREIGN KEY (IDSubject) REFERENCES Ideology(IDSubject)
);
