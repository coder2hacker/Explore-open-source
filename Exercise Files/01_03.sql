use AdventureWorksDW2014;

-- basic filter with WHERE
-- get sales of a specific product only
SELECT *
FROM FactInternetSales s
INNER JOIN DimProduct p ON s.ProductKey = p.ProductKey
WHERE p.EnglishProductName = 'Road-650 Black, 62'

-- non-equi-filters
-- get all orders for 2013
SELECT *
FROM FactInternetSales s
INNER JOIN DimProduct p ON s.ProductKey = p.ProductKey
WHERE	s.OrderDate >= '2013-01-01'
AND		s.OrderDate <= '2013-12-31'

-- also can use "between" for dates
SELECT *
FROM FactInternetSales s
INNER JOIN DimProduct p ON s.ProductKey = p.ProductKey
WHERE s.OrderDate BETWEEN '2013-01-01' AND '2013-12-31';

-- filter for multiple values using IN
SELECT *
FROM FactInternetSales s
INNER JOIN DimProduct p ON s.ProductKey = p.ProductKey
WHERE p.EnglishProductName in( 
		'Mountain-400-W Silver, 38',
		'Mountain-400-W Silver, 40',
		'Mountain-400-W Silver, 42',
		'Mountain-400-W Silver, 46')


-- find all current and future matches with LIKE
SELECT *
FROM FactInternetSales s
INNER JOIN DimProduct p ON s.ProductKey = p.ProductKey
WHERE p.EnglishProductName LIKE 'Mountain%' --put % where you want wildcard