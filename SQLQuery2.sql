
INSERT INTO [dbo].[Students]

           ([StudentID]
           ,[StudentName]
           ,[StudentPhone]
           ,[StudentEmail]
           ,[IsActive])
     VALUES
           ('S2'
           ,'Ashu'
           ,'9305559999'
           ,'ashuGL78687@gmail.com'
           ,1  
		   ),

		   ('S3'
		   , 'ADITI'
		   ,'9949494'
		   ,'aditi@gmai.com' 
		  , 0
		   )


GO

SELECT * FROM dbo.Students

--select * from DBO.Students where IsActive=1

--Select * from dbo.Students where StudentEmail='ayushsukla78687@gmail.com'
