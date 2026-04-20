CREATE TABLE IF NOT EXISTS жд_составы (
                                          id BIGSERIAL PRIMARY KEY,
                                          train_number VARCHAR(20) NOT NULL UNIQUE,
                                          composition_name VARCHAR(100) NOT NULL,
                                          number_of_cars INTEGER NOT NULL CHECK (number_of_cars > 0),
                                          total_weight DECIMAL(10, 2) NOT NULL CHECK (total_weight >= 0),
                                          length DECIMAL(8, 2) NOT NULL CHECK (length >= 0),
                                          locomotive_series VARCHAR(50),
                                          destination VARCHAR(150) NOT NULL,
                                          departure_time TIMESTAMP,
                                          status VARCHAR(20) DEFAULT 'FORMING',
                                          created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- Индексы для оптимизации
CREATE INDEX idx_train_number ON жд_составы(train_number);
CREATE INDEX idx_status ON жд_составы(status);
CREATE INDEX idx_destination ON жд_составы(destination);

-- Комментарии к таблице
COMMENT ON TABLE жд_составы IS 'Железнодорожные составы';
COMMENT ON COLUMN жд_составы.train_number IS 'Номер поезда';
COMMENT ON COLUMN жд_составы.composition_name IS 'Название состава';
COMMENT ON COLUMN жд_составы.number_of_cars IS 'Количество вагонов';
COMMENT ON COLUMN жд_составы.total_weight IS 'Общий вес (тонн)';
COMMENT ON COLUMN жд_составы.length IS 'Длина состава (метров)';