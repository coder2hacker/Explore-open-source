-- ================================================
-- Template generated from Template Explorer using:
-- Create Procedure (New Menu).SQL
--
-- Use the Specify Values for Template Parameters 
-- command (Ctrl-Shift-M) to fill in the parameter 
-- values below.
--
-- This block of comments will not be included in
-- the definition of the procedure.
-- ================================================
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
-- =============================================
-- Author:		<Author,,Name>
-- Create date: <Create Date,,>
-- Description:	<Description,,>
-- =============================================
CREATE PROCEDURE [dbo].[Sp_Trainee]
 @Trainee_Name nvarchar(50),
 @Enrollment_Date date,
 @Phone_No nvarchar(50),
 @Department_ID int,
 @DateOf_Joining date,
 @Email_ID nvarchar(50),
 @Password nvarchar(50),
 @InputString varchar
AS
BEGIN
	-- SET NOCOUNT ON added to prevent extra result sets from
	-- interfering with SELECT statements.
	SET NOCOUNT ON;
	If(@InputString = 'Select')
	BEGIN
    -- Insert statements for procedure here
	SELECT [TraineeName],
	[EnrollmentDate],
	[PhoneNo],
	[DepartmentID],
	[DateOfJoining],
	[EmailID],
	[Password]
    FROM  [dbo].[Trainee] Where [TraineeName]=@Trainee_Name  and [EnrollmentDate]=@Enrollment_Date and [PhoneNo]=@Phone_No and [DepartmentID]=@Department_ID and [DateOfJoining]=@DateOf_Joining and [EmailID]=@Email_ID and [Password]=@Password
    END
	Else If (@InputString = 'Insert')
	BEGIN
	INSERT INTO [dbo].[Trainee]
           ([TraineeName]
	,[EnrollmentDate]
	,[PhoneNo]
	,[DepartmentID]
	,[DateOfJoining]
	,[EmailID]
	,[Password])
     VALUES(@Trainee_Name,
	        @Enrollment_Date,
			@Phone_No,
			@Department_ID,
			@DateOf_Joining,
			@Email_ID,
			@Password)
	     END

	Else If (@InputString = 'Insert')
	BEGIN
	INSERT INTO [dbo].[Trainee]
           ([TraineeName]
	,[EnrollmentDate]
	,[PhoneNo]
	,[DepartmentID]
	,[DateOfJoining]
	,[EmailID]
	,[Password])
     VALUES(@Trainee_Name,
	        @Enrollment_Date,
			@Phone_No,
			@Department_ID,
			@DateOf_Joining,
			@Email_ID,
			@Password)
	END
END
GO
