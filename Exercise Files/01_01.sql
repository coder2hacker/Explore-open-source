use AdventureWorksDW2014;

-- select all columns
select * from FactInternetSales;

-- limiting results
select top 1000 * from FactInternetSales; -- in other DB's use limit 1000;

-- select using column names
SELECT [ProductKey]
      ,[OrderDateKey]
      ,[DueDateKey]
      ,[ShipDateKey]
      ,[CustomerKey]
      ,[PromotionKey]
      ,[CurrencyKey]
      ,[SalesTerritoryKey]
      ,[SalesOrderNumber]
      ,[SalesOrderLineNumber]
      ,[RevisionNumber]
      ,[OrderQuantity]
      ,[UnitPrice]
      ,[ExtendedAmount]
      ,[UnitPriceDiscountPct]
      ,[DiscountAmount]
      ,[ProductStandardCost]
      ,[TotalProductCost]
      ,[SalesAmount]
      ,[TaxAmt]
      ,[Freight]
      ,[CarrierTrackingNumber]
      ,[CustomerPONumber]
      ,[OrderDate]
      ,[DueDate]
      ,[ShipDate]
  FROM [dbo].[FactInternetSales]


-- select some and use aliases
SELECT TOP 1000
		[SalesOrderNumber] as 'OrderNumber'
      ,	[SalesOrderLineNumber] as 'LineNumber'
      ,	[OrderQuantity] as 'Quantity'
      ,	[UnitPrice] as 'Price'
      ,	[DiscountAmount] as 'Discount'
      ,	[SalesAmount] as 'Sales'
      ,	[TaxAmt] as 'Taxes'      
      ,	[OrderDate] as 'Date'      
FROM [dbo].[FactInternetSales]