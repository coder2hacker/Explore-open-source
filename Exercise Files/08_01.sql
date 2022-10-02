use AdventureWorksDW2014;

-- Employee Table
select *
from DimEmployee

-- Analyzing Employee Data
-- How many active employees did we have on Nov 13th, 2013?
SELECT COUNT(1)
FROM DimEmployee emp
WHERE StartDate <= '2013-01-01'
AND	(
		EndDate > '2013-01-01'
	OR
		EndDate IS NULL
	)

-- start with dates table
select top 100 *
from DimDate

-- Show me a trend of active employees by Month
-- Start by getting the Daily count
SELECT
		dt.FullDateAlternateKey as 'Date'
	,	count(1) as ActiveCount	
FROM DimDate dt
LEFT JOIN	(SELECT 'Active' as 'EmpStatus', * FROM DimEmployee) emp
	-- regular active employees
	ON (dt.FullDateAlternateKey between emp.StartDate and ISNULL(emp.EndDate,'9999-12-31'))
GROUP BY
		dt.FullDateAlternateKey
ORDER BY
		1

-- Show EOM Function
select DISTINCT top 20 EOMONTH(FullDateAlternateKey)
from DimDate d
order by 1


-- These counts are cumulative, so for monthly totals take the last day of the month
SELECT
		dt.FullDateAlternateKey as 'Date'
	,	count(1) as ActiveCount	
FROM DimDate dt
LEFT JOIN	(SELECT 'Active' as 'EmpStatus', * FROM DimEmployee) emp
	-- regular active employees
	ON (dt.FullDateAlternateKey between emp.StartDate and ISNULL(emp.EndDate,'9999-12-31'))
WHERE
	dt.FullDateAlternateKey = EOMONTH(dt.FullDateAlternateKey)
GROUP BY
		dt.FullDateAlternateKey
ORDER BY
		1





