use AdventureWorksDW2014;

-- Show a 6 week rolling average of Weekly Sales for 2013

-- first create weekly sales totals
SELECT	SUM(s.SalesAmount) 'WeeklySales' 
	,	DATEPART(ww, s.OrderDate) as 'WeekNum'
FROM	FactInternetSales s
WHERE	YEAR(s.OrderDate) = 2013
GROUP BY
		DATEPART(ww, s.OrderDate)
ORDER BY
		DATEPART(ww, s.OrderDate) ASC

-- use that subquery as our source and calculate the moving average
SELECT
		AVG(WeeklySales) OVER (ORDER BY WeekNum ROWS BETWEEN 6 PRECEDING AND CURRENT ROW) as AvgSales
	,	WeeklySales as 'TotalSales'
	,	WeekNum
FROM (
	SELECT	SUM(s.SalesAmount) 'WeeklySales' 
		,	DATEPART(ww, s.OrderDate) as 'WeekNum'
	FROM	FactInternetSales s
	WHERE	YEAR(s.OrderDate) = 2013
	GROUP BY
			DATEPART(ww, s.OrderDate)
	) AS s
GROUP BY
		WeekNum, WeeklySales
ORDER BY
		WeekNum ASC


-- Running Total
SELECT
		SUM(MonthlySales) OVER (PARTITION BY SalesYear ORDER BY SalesMonth ROWS UNBOUNDED PRECEDING) as YTDSales
	,	MonthlySales as 'MonthlySales'
	,	SalesYear
	,	SalesMonth
FROM (
	SELECT	SUM(s.SalesAmount) 'MonthlySales' 
		,	MONTH(s.OrderDate) as 'SalesMonth'
		,	year(s.OrderDate) as 'SalesYear'
	FROM	FactInternetSales s
	GROUP BY
			MONTH(s.OrderDate)
		,	year(s.OrderDate)
	) AS s
GROUP BY
		SalesMonth, SalesYear, MonthlySales
ORDER BY
		SalesYear, SalesMonth ASC