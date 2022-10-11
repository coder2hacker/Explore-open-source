-- ================================================
-- Template generated from Template Explorer using:
-- Create Scalar Function (New Menu).SQL
--
-- Use the Specify Values for Template Parameters 
-- command (Ctrl-Shift-M) to fill in the parameter 
-- values below.
--
-- This block of comments will not be included in
-- the definition of the function.
-- ================================================
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
-- =============================================
-- Author:		<Author,,Name>
-- Create date: <Create Date, ,>
-- Description:	<Description, ,>
-- =============================================

-- ================================================
-- Template generated from Template Explorer using:
-- Create Scalar Function (New Menu).SQL
--
-- Use the Specify Values for Template Parameters 
-- command (Ctrl-Shift-M) to fill in the parameter 
-- values below.
--
-- This block of comments will not be included in
-- the definition of the function.
-- ================================================
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
-- =============================================
-- Author:		<Author,,Name>
-- Create date: <Create Date, ,>
-- Description:	<Description, ,>


CREATE FUNCTION production.DisplayQauntity
(
	@store_id int,
	@product_id int
)

RETURNS int
AS
BEGIN
	DECLARE @DisplayQauntity int
	SELECT @DisplayQauntity = quantity
	FROM [production].[stocks]
	WHERE store_id=@store_id and product_id= @product_id
	RETURN  @DisplayQauntity 
END
GO
select production.DisplayQauntity(1,3) AS 'Display Qauntity'

--store id and product_id as parameter 
--and quantity as return
