CREATE TABLE [dbo].[Students](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[StudentID] [varchar](50) NOT NULL,
	[StudentName] [varchar](150) NOT NULL,
	[StudentPhone] [varchar](15) NOT NULL,
	[StudentEmail] [varchar](200) NOT NULL,
	[IsActive] [bit] NOT NULL,
 CONSTRAINT [PK_Students] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[Employee](
id int IDENTITY(1,1) NOT NULL,
employeeName varchar(30) NOT NULL,
employeeNomber varchar(15)NOT NULL,
emplyeeEmail varchar(22) NOT NULL,
IsActive bit NOT NULL,

Constraint PK_employee PRIMARY KEY(
id ASC 
) 
) ON [PRIMARY] 




