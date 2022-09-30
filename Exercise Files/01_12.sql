use AdventureWorksDW2014;

-- Find the top products of 2013
-- using ROW_NUMBER() as a Rank function
-- fragile solution
SELECT 
		ROW_NUMBER() OVER (ORDER BY sum(s.SalesAmount) DESC)  AS 'Rank'
	,	count(DISTINCT s.SalesOrderNumber) 'OrderCount' -- use 1 instead of a field for faster performance
	,	sum(s.SalesAmount) 'Sales' 
	,	cat.EnglishProductCategoryName 'Category'
    ,	sub.EnglishProductSubcategoryName 'SubCategory'	
FROM FactInternetSales s
INNER JOIN DimProduct p ON s.ProductKey = p.ProductKey
INNER JOIN DimProductSubcategory sub ON p.ProductSubcategoryKey = sub.ProductSubcategoryKey
INNER JOIN DimProductCategory cat ON sub.ProductCategoryKey = cat.ProductCategoryKey
-- filter
WHERE YEAR(s.OrderDate) = 2013 --use date function to parse year
-- must use group by in order for aggregation to work properly
GROUP BY
		cat.EnglishProductCategoryName -- column aliases aren't allowed
    ,	sub.EnglishProductSubcategoryName	

ORDER BY 3 DESC;


-- use RANK() function instead
-- when RANK() and ROW_NUBER() have the same order by the restults are the same
SELECT 
		ROW_NUMBER() OVER (ORDER BY sum(s.SalesAmount) DESC)  AS 'Rank'
	,	count(DISTINCT s.SalesOrderNumber) 'OrderCount' -- use 1 instead of a field for faster performance
	,	RANK() OVER (ORDER BY sum(s.SalesAmount) DESC) 'SalesRank' 
	,	sum(s.SalesAmount) 'TotalSales'
	,	cat.EnglishProductCategoryName 'Category'
    ,	sub.EnglishProductSubcategoryName 'SubCategory'	
FROM FactInternetSales s
INNER JOIN DimProduct p ON s.ProductKey = p.ProductKey
INNER JOIN DimProductSubcategory sub ON p.ProductSubcategoryKey = sub.ProductSubcategoryKey
INNER JOIN DimProductCategory cat ON sub.ProductCategoryKey = cat.ProductCategoryKey
-- filter
WHERE YEAR(s.OrderDate) = 2013 --use date function to parse year
-- must use group by in order for aggregation to work properly
GROUP BY
		cat.EnglishProductCategoryName -- column aliases aren't allowed
    ,	sub.EnglishProductSubcategoryName	

ORDER BY cat.EnglishProductCategoryName, sub.EnglishProductSubcategoryName;


-- Show the top product Sub Categories for each year
SELECT 		
		count(DISTINCT s.SalesOrderNumber) 'OrderCount' -- use 1 instead of a field for faster performance
	,	RANK() OVER (PARTITION BY YEAR(s.OrderDate) ORDER BY sum(s.SalesAmount) DESC) 'SalesRank' 
	,	sum(s.SalesAmount) 'TotalSales'
	,	cat.EnglishProductCategoryName 'Category'
    ,	sub.EnglishProductSubcategoryName 'SubCategory'	
	,	YEAR(s.OrderDate) 'Year'
FROM FactInternetSales s
INNER JOIN DimProduct p ON s.ProductKey = p.ProductKey
INNER JOIN DimProductSubcategory sub ON p.ProductSubcategoryKey = sub.ProductSubcategoryKey
INNER JOIN DimProductCategory cat ON sub.ProductCategoryKey = cat.ProductCategoryKey
-- must use group by in order for aggregation to work properly
GROUP BY
		cat.EnglishProductCategoryName -- column aliases aren't allowed
    ,	sub.EnglishProductSubcategoryName	
	,	YEAR(s.OrderDate)

ORDER BY YEAR(s.OrderDate), SUM(s.SalesAmount) DESC;