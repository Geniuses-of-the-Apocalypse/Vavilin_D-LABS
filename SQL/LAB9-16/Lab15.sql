USE labHOI4;

DELIMITER //

CREATE PROCEDURE GetCountryInfo(IN p_INN VARCHAR(20))
BEGIN
    SELECT 
        c.NameCountry, 
        f.NameFraction, 
        c.MarkAVG
    FROM Country c
    LEFT JOIN Fraction f ON c.IDGroup = f.IDFraction
    WHERE c.INN = p_INN;
END //

DELIMITER ;

CALL GetCountryInfo('GER');
CALL GetCountryInfo('SOV');