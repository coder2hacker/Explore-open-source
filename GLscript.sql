USE [master]
GO
/****** Object:  Database [online_shopping]    Script Date: 9/26/2022 7:53:03 PM ******/
CREATE DATABASE [online_shopping]
 CONTAINMENT = NONE
 ON  PRIMARY 
( NAME = N'online_shopping', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL15.MSSQLSERVER\MSSQL\DATA\online_shopping.mdf' , SIZE = 8192KB , MAXSIZE = UNLIMITED, FILEGROWTH = 65536KB )
 LOG ON 
( NAME = N'online_shopping_log', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL15.MSSQLSERVER\MSSQL\DATA\online_shopping_log.ldf' , SIZE = 8192KB , MAXSIZE = 2048GB , FILEGROWTH = 65536KB )
 WITH CATALOG_COLLATION = DATABASE_DEFAULT
GO
ALTER DATABASE [online_shopping] SET COMPATIBILITY_LEVEL = 150
GO
IF (1 = FULLTEXTSERVICEPROPERTY('IsFullTextInstalled'))
begin
EXEC [online_shopping].[dbo].[sp_fulltext_database] @action = 'enable'
end
GO
ALTER DATABASE [online_shopping] SET ANSI_NULL_DEFAULT OFF 
GO
ALTER DATABASE [online_shopping] SET ANSI_NULLS OFF 
GO
ALTER DATABASE [online_shopping] SET ANSI_PADDING OFF 
GO
ALTER DATABASE [online_shopping] SET ANSI_WARNINGS OFF 
GO
ALTER DATABASE [online_shopping] SET ARITHABORT OFF 
GO
ALTER DATABASE [online_shopping] SET AUTO_CLOSE OFF 
GO
ALTER DATABASE [online_shopping] SET AUTO_SHRINK OFF 
GO
ALTER DATABASE [online_shopping] SET AUTO_UPDATE_STATISTICS ON 
GO
ALTER DATABASE [online_shopping] SET CURSOR_CLOSE_ON_COMMIT OFF 
GO
ALTER DATABASE [online_shopping] SET CURSOR_DEFAULT  GLOBAL 
GO
ALTER DATABASE [online_shopping] SET CONCAT_NULL_YIELDS_NULL OFF 
GO
ALTER DATABASE [online_shopping] SET NUMERIC_ROUNDABORT OFF 
GO
ALTER DATABASE [online_shopping] SET QUOTED_IDENTIFIER OFF 
GO
ALTER DATABASE [online_shopping] SET RECURSIVE_TRIGGERS OFF 
GO
ALTER DATABASE [online_shopping] SET  ENABLE_BROKER 
GO
ALTER DATABASE [online_shopping] SET AUTO_UPDATE_STATISTICS_ASYNC OFF 
GO
ALTER DATABASE [online_shopping] SET DATE_CORRELATION_OPTIMIZATION OFF 
GO
ALTER DATABASE [online_shopping] SET TRUSTWORTHY OFF 
GO
ALTER DATABASE [online_shopping] SET ALLOW_SNAPSHOT_ISOLATION OFF 
GO
ALTER DATABASE [online_shopping] SET PARAMETERIZATION SIMPLE 
GO
ALTER DATABASE [online_shopping] SET READ_COMMITTED_SNAPSHOT OFF 
GO
ALTER DATABASE [online_shopping] SET HONOR_BROKER_PRIORITY OFF 
GO
ALTER DATABASE [online_shopping] SET RECOVERY FULL 
GO
ALTER DATABASE [online_shopping] SET  MULTI_USER 
GO
ALTER DATABASE [online_shopping] SET PAGE_VERIFY CHECKSUM  
GO
ALTER DATABASE [online_shopping] SET DB_CHAINING OFF 
GO
ALTER DATABASE [online_shopping] SET FILESTREAM( NON_TRANSACTED_ACCESS = OFF ) 
GO
ALTER DATABASE [online_shopping] SET TARGET_RECOVERY_TIME = 60 SECONDS 
GO
ALTER DATABASE [online_shopping] SET DELAYED_DURABILITY = DISABLED 
GO
ALTER DATABASE [online_shopping] SET ACCELERATED_DATABASE_RECOVERY = OFF  
GO
EXEC sys.sp_db_vardecimal_storage_format N'online_shopping', N'ON'
GO
ALTER DATABASE [online_shopping] SET QUERY_STORE = OFF
GO
USE [online_shopping]
GO
/****** Object:  Table [dbo].[Tbl_Category]    Script Date: 9/26/2022 7:53:04 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Tbl_Category](
	[CategoryId] [int] IDENTITY(1,1) NOT NULL,
	[CategoryName] [nvarchar](50) NULL,
	[IsActive] [bit] NULL,
	[IsDelete] [bit] NULL,
	[CreatedAt] [datetime] NULL,
	[ModifiedAt] [datetime] NULL,
	[DeletedAt] [datetime] NULL,
 CONSTRAINT [PK_Tbl_Category] PRIMARY KEY CLUSTERED 
(
	[CategoryId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  View [dbo].[categoryid]    Script Date: 9/26/2022 7:53:04 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
Create View 
[dbo].[categoryid] 
	as select CategoryId from Tbl_Category
GO
/****** Object:  Table [dbo].[Tbl_Users]    Script Date: 9/26/2022 7:53:04 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Tbl_Users](
	[UserId] [int] IDENTITY(1,1) NOT NULL,
	[FirstName] [nvarchar](50) NULL,
	[LastName] [nvarchar](50) NULL,
	[EmailId] [nvarchar](100) NULL,
	[Password] [nvarchar](50) NULL,
	[IsActive] [bit] NULL,
	[IsDelete] [bit] NULL,
	[CreatedOn] [datetime] NULL,
	[ModifiedOn] [datetime] NULL,
	[DOB] [date] NULL,
	[GenderId] [int] NULL,
	[Phoneno] [nvarchar](50) NULL,
	[LastLogin] [datetime] NULL,
 CONSTRAINT [PK_Tbl_Members] PRIMARY KEY CLUSTERED 
(
	[UserId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  View [dbo].[usercount]    Script Date: 9/26/2022 7:53:04 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE view [dbo].[usercount]
as  select count(*) as 'Total Users' from [Tbl_Users]
GO
/****** Object:  Table [dbo].[Tbl_Product]    Script Date: 9/26/2022 7:53:04 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Tbl_Product](
	[ProductId] [int] IDENTITY(1,1) NOT NULL,
	[ProductName] [varchar](100) NULL,
	[CategoryId] [int] NULL,
	[IsActive] [bit] NULL,
	[IsDelete] [bit] NULL,
	[CreatedDate] [date] NULL,
	[ModifiedDate] [date] NULL,
	[Description] [varchar](500) NULL,
	[ProductImage] [varchar](2000) NULL,
	[Price] [decimal](18, 2) NULL,
	[IsFeatured] [bit] NULL,
 CONSTRAINT [PK_Tbl_Product] PRIMARY KEY CLUSTERED 
(
	[ProductId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  View [dbo].[productcount]    Script Date: 9/26/2022 7:53:04 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE view [dbo].[productcount]
as  select count(*) as 'Total products' from [Tbl_Product]
GO
/****** Object:  View [dbo].[categorycount]    Script Date: 9/26/2022 7:53:04 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create view [dbo].[categorycount]
as  select count(*) as 'Total categories' from [Tbl_Category]
GO
/****** Object:  Table [dbo].[Tbl_Orders]    Script Date: 9/26/2022 7:53:04 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Tbl_Orders](
	[OrderId] [int] IDENTITY(1,1) NOT NULL,
	[UserId] [int] NULL,
	[ProductId] [int] NULL,
	[TotalPrice] [decimal](18, 2) NULL,
	[PaymentId] [int] NULL,
	[OrderDate] [datetime] NULL,
 CONSTRAINT [PK_Tbl_Orders] PRIMARY KEY CLUSTERED 
(
	[OrderId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  View [dbo].[ordercount]    Script Date: 9/26/2022 7:53:04 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create view [dbo].[ordercount]
as  select count(*) as 'Total categories' from [Tbl_Orders]
GO
/****** Object:  Table [dbo].[Tbl_Address]    Script Date: 9/26/2022 7:53:04 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Tbl_Address](
	[AddressId] [int] IDENTITY(1,1) NOT NULL,
	[UserId] [int] NULL,
	[AddressLine1] [nvarchar](50) NULL,
	[AddressLine2] [nvarchar](50) NULL,
	[City] [nvarchar](50) NULL,
	[PinCode] [nvarchar](50) NULL,
	[Country] [nvarchar](50) NULL,
	[Phone] [nvarchar](50) NULL,
 CONSTRAINT [PK_Tbl_Address] PRIMARY KEY CLUSTERED 
(
	[AddressId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Tbl_Admin]    Script Date: 9/26/2022 7:53:04 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Tbl_Admin](
	[ad_id] [int] IDENTITY(1,1) NOT NULL,
	[ad_username] [nvarchar](50) NULL,
	[ad_password] [nvarchar](50) NULL,
	[ad_lastLogin] [datetime] NULL,
	[LoginFailedCount] [int] NULL,
	[LastAccessedDate] [datetime] NULL,
	[AccountLocked] [bit] NULL,
 CONSTRAINT [PK_Tbl_Admin] PRIMARY KEY CLUSTERED 
(
	[ad_id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Tbl_Cart]    Script Date: 9/26/2022 7:53:04 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Tbl_Cart](
	[CartId] [int] IDENTITY(1,1) NOT NULL,
	[ProductId] [int] NULL,
	[SessionId] [int] NULL,
	[Quantity] [int] NULL,
	[AddedOn] [datetime] NULL,
	[UpdatedOn] [datetime] NULL,
 CONSTRAINT [PK_Tbl_Cart] PRIMARY KEY CLUSTERED 
(
	[CartId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Tbl_Payment]    Script Date: 9/26/2022 7:53:04 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Tbl_Payment](
	[PaymentId] [int] NOT NULL,
	[OrderId] [int] NULL,
	[Amount] [decimal](18, 2) NULL,
	[Provider] [nvarchar](50) NULL,
	[Status] [nvarchar](50) NULL,
	[CreatedAt] [datetime] NULL,
	[ModifiedAt] [datetime] NULL,
 CONSTRAINT [PK_Tbl_Payment] PRIMARY KEY CLUSTERED 
(
	[PaymentId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Tbl_Session]    Script Date: 9/26/2022 7:53:04 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Tbl_Session](
	[SessionId] [int] IDENTITY(1,1) NOT NULL,
	[UserId] [int] NULL,
	[Total] [decimal](18, 2) NULL,
	[CreatedAt] [datetime] NULL,
	[ModifiedAt] [datetime] NULL,
 CONSTRAINT [PK_Tbl_Session] PRIMARY KEY CLUSTERED 
(
	[SessionId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Tbl_ShippingDetails]    Script Date: 9/26/2022 7:53:04 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Tbl_ShippingDetails](
	[ShippingDetailId] [int] IDENTITY(1,1) NOT NULL,
	[MemberId] [int] NULL,
	[AddressLine] [varchar](100) NULL,
	[City] [varchar](50) NULL,
	[State] [varchar](50) NULL,
	[Country] [varchar](50) NULL,
	[ZipCode] [varchar](50) NULL,
	[OrderId] [varchar](50) NULL,
	[AmountPaid] [decimal](18, 0) NULL,
	[PaymentType] [varchar](50) NULL,
 CONSTRAINT [PK_Tbl_ShippingAddress] PRIMARY KEY CLUSTERED 
(
	[ShippingDetailId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Tbl_UserPayment]    Script Date: 9/26/2022 7:53:04 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Tbl_UserPayment](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[UserId] [int] NULL,
	[PaymentType] [nvarchar](50) NULL,
	[Provider] [varchar](50) NULL,
	[AccountNo] [nvarchar](50) NULL,
	[Expiry] [date] NULL,
 CONSTRAINT [PK_Tbl_UserPayment] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
SET IDENTITY_INSERT [dbo].[Tbl_Admin] ON 
GO
INSERT [dbo].[Tbl_Admin] ([ad_id], [ad_username], [ad_password], [ad_lastLogin], [LoginFailedCount], [LastAccessedDate], [AccountLocked]) VALUES (1, N'root', N'admin123', CAST(N'2022-09-25T22:53:00.297' AS DateTime), NULL, NULL, NULL)
GO
INSERT [dbo].[Tbl_Admin] ([ad_id], [ad_username], [ad_password], [ad_lastLogin], [LoginFailedCount], [LastAccessedDate], [AccountLocked]) VALUES (2, N'admin', N'admin456', CAST(N'2022-09-25T14:03:51.187' AS DateTime), NULL, NULL, NULL)
GO
INSERT [dbo].[Tbl_Admin] ([ad_id], [ad_username], [ad_password], [ad_lastLogin], [LoginFailedCount], [LastAccessedDate], [AccountLocked]) VALUES (3, N'seller', N'admin789', NULL, NULL, NULL, NULL)
GO
SET IDENTITY_INSERT [dbo].[Tbl_Admin] OFF
GO
SET IDENTITY_INSERT [dbo].[Tbl_Category] ON 
GO
INSERT [dbo].[Tbl_Category] ([CategoryId], [CategoryName], [IsActive], [IsDelete], [CreatedAt], [ModifiedAt], [DeletedAt]) VALUES (1, N'Men', 1, 0, NULL, NULL, NULL)
GO
INSERT [dbo].[Tbl_Category] ([CategoryId], [CategoryName], [IsActive], [IsDelete], [CreatedAt], [ModifiedAt], [DeletedAt]) VALUES (2, N'Women', 1, 0, NULL, NULL, NULL)
GO
INSERT [dbo].[Tbl_Category] ([CategoryId], [CategoryName], [IsActive], [IsDelete], [CreatedAt], [ModifiedAt], [DeletedAt]) VALUES (3, N'Kids', 1, 0, NULL, NULL, NULL)
GO
INSERT [dbo].[Tbl_Category] ([CategoryId], [CategoryName], [IsActive], [IsDelete], [CreatedAt], [ModifiedAt], [DeletedAt]) VALUES (4, N'Handbag', NULL, NULL, NULL, NULL, NULL)
GO
INSERT [dbo].[Tbl_Category] ([CategoryId], [CategoryName], [IsActive], [IsDelete], [CreatedAt], [ModifiedAt], [DeletedAt]) VALUES (5, N'Shoes', 1, 0, CAST(N'2022-09-25T22:49:29.413' AS DateTime), CAST(N'2022-09-25T22:49:29.413' AS DateTime), NULL)
GO
INSERT [dbo].[Tbl_Category] ([CategoryId], [CategoryName], [IsActive], [IsDelete], [CreatedAt], [ModifiedAt], [DeletedAt]) VALUES (6, N'Female', 1, 0, CAST(N'2022-09-25T22:54:06.113' AS DateTime), CAST(N'2022-09-25T22:54:06.113' AS DateTime), NULL)
GO
SET IDENTITY_INSERT [dbo].[Tbl_Category] OFF
GO
SET IDENTITY_INSERT [dbo].[Tbl_Orders] ON 
GO
INSERT [dbo].[Tbl_Orders] ([OrderId], [UserId], [ProductId], [TotalPrice], [PaymentId], [OrderDate]) VALUES (4, 4, 2, CAST(656.00 AS Decimal(18, 2)), 1, CAST(N'2002-05-05T00:00:00.000' AS DateTime))
GO
SET IDENTITY_INSERT [dbo].[Tbl_Orders] OFF
GO
INSERT [dbo].[Tbl_Payment] ([PaymentId], [OrderId], [Amount], [Provider], [Status], [CreatedAt], [ModifiedAt]) VALUES (1, NULL, CAST(656.00 AS Decimal(18, 2)), NULL, N'Pending', NULL, NULL)
GO
SET IDENTITY_INSERT [dbo].[Tbl_Product] ON 
GO
INSERT [dbo].[Tbl_Product] ([ProductId], [ProductName], [CategoryId], [IsActive], [IsDelete], [CreatedDate], [ModifiedDate], [Description], [ProductImage], [Price], [IsFeatured]) VALUES (1, N'T-shirt', 1, 1, 0, NULL, NULL, N'Men T-shirt', N'Penguins.jpg', CAST(76.00 AS Decimal(18, 2)), 1)
GO
INSERT [dbo].[Tbl_Product] ([ProductId], [ProductName], [CategoryId], [IsActive], [IsDelete], [CreatedDate], [ModifiedDate], [Description], [ProductImage], [Price], [IsFeatured]) VALUES (2, N'Shirts', 1, 1, 0, CAST(N'2016-08-09' AS Date), CAST(N'2016-08-09' AS Date), N'Men Shirts', N'samsung-galaxy-on5-spotted-1.jpg', CAST(656.00 AS Decimal(18, 2)), 1)
GO
INSERT [dbo].[Tbl_Product] ([ProductId], [ProductName], [CategoryId], [IsActive], [IsDelete], [CreatedDate], [ModifiedDate], [Description], [ProductImage], [Price], [IsFeatured]) VALUES (3, N'Jeans', 2, 1, 0, CAST(N'2016-08-09' AS Date), CAST(N'2016-08-09' AS Date), N'Womens Jeans', N'download (1).jpg', CAST(350.00 AS Decimal(18, 2)), 0)
GO
INSERT [dbo].[Tbl_Product] ([ProductId], [ProductName], [CategoryId], [IsActive], [IsDelete], [CreatedDate], [ModifiedDate], [Description], [ProductImage], [Price], [IsFeatured]) VALUES (4, N'Trousers', 1, 1, 0, CAST(N'2016-08-09' AS Date), CAST(N'2016-08-09' AS Date), N'Men Trousers', N'download.jpg', CAST(88.00 AS Decimal(18, 2)), 1)
GO
INSERT [dbo].[Tbl_Product] ([ProductId], [ProductName], [CategoryId], [IsActive], [IsDelete], [CreatedDate], [ModifiedDate], [Description], [ProductImage], [Price], [IsFeatured]) VALUES (5, N'Top', 2, 1, 0, CAST(N'2016-09-28' AS Date), CAST(N'2016-09-28' AS Date), N'Women Top', N'3_download (1).jpg', CAST(90000.00 AS Decimal(18, 2)), 1)
GO
INSERT [dbo].[Tbl_Product] ([ProductId], [ProductName], [CategoryId], [IsActive], [IsDelete], [CreatedDate], [ModifiedDate], [Description], [ProductImage], [Price], [IsFeatured]) VALUES (6, N'Lehnga', 2, 1, 0, CAST(N'2016-09-28' AS Date), CAST(N'2016-09-28' AS Date), N'Women Lehnga', N'images.jpg', CAST(850.00 AS Decimal(18, 2)), 1)
GO
INSERT [dbo].[Tbl_Product] ([ProductId], [ProductName], [CategoryId], [IsActive], [IsDelete], [CreatedDate], [ModifiedDate], [Description], [ProductImage], [Price], [IsFeatured]) VALUES (7, N'Dhangree', 2, 1, 0, CAST(N'2016-09-28' AS Date), CAST(N'2016-09-28' AS Date), N'Women Dhangree', N'Htc-Desire-516-white--SDL232582179-1-71d4a.jpg', CAST(7600.00 AS Decimal(18, 2)), 1)
GO
INSERT [dbo].[Tbl_Product] ([ProductId], [ProductName], [CategoryId], [IsActive], [IsDelete], [CreatedDate], [ModifiedDate], [Description], [ProductImage], [Price], [IsFeatured]) VALUES (8, N'Kurti', 1, 1, 0, CAST(N'2022-09-26' AS Date), CAST(N'2022-09-26' AS Date), N'Women Kurti', NULL, NULL, NULL)
GO
INSERT [dbo].[Tbl_Product] ([ProductId], [ProductName], [CategoryId], [IsActive], [IsDelete], [CreatedDate], [ModifiedDate], [Description], [ProductImage], [Price], [IsFeatured]) VALUES (9, N'Kurta', 1, 1, 0, CAST(N'2022-09-26' AS Date), CAST(N'2022-09-26' AS Date), N'Men Kurta', NULL, NULL, NULL)
GO
INSERT [dbo].[Tbl_Product] ([ProductId], [ProductName], [CategoryId], [IsActive], [IsDelete], [CreatedDate], [ModifiedDate], [Description], [ProductImage], [Price], [IsFeatured]) VALUES (10, N'Saree', 2, 1, 0, CAST(N'2022-09-26' AS Date), CAST(N'2022-09-26' AS Date), N'Women Saree', NULL, NULL, NULL)
GO
INSERT [dbo].[Tbl_Product] ([ProductId], [ProductName], [CategoryId], [IsActive], [IsDelete], [CreatedDate], [ModifiedDate], [Description], [ProductImage], [Price], [IsFeatured]) VALUES (11, N'T-shirt', 1, 1, 0, CAST(N'2022-09-26' AS Date), CAST(N'2022-09-26' AS Date), N'Men''s Casual T-shirt', N'Screenshot (1).png', CAST(656.00 AS Decimal(18, 2)), NULL)
GO
SET IDENTITY_INSERT [dbo].[Tbl_Product] OFF
GO
SET IDENTITY_INSERT [dbo].[Tbl_ShippingDetails] ON 
GO
INSERT [dbo].[Tbl_ShippingDetails] ([ShippingDetailId], [MemberId], [AddressLine], [City], [State], [Country], [ZipCode], [OrderId], [AmountPaid], [PaymentType]) VALUES (1, 4, N'sdsad', N'sdasd', N'dwfef', N'ewdwd', N'wqewqe', N'30b8dcac-4e3e-4596-b171-ab8be74868c1', CAST(8450 AS Decimal(18, 0)), N'Pay Using Debit/Credit Card')
GO
INSERT [dbo].[Tbl_ShippingDetails] ([ShippingDetailId], [MemberId], [AddressLine], [City], [State], [Country], [ZipCode], [OrderId], [AmountPaid], [PaymentType]) VALUES (2, 4, N'Karol Bagh', N'Delhi', N'New Delhi', N'India', N'110009', N'428f09f8-141b-49b9-be38-77f5a288ea73', CAST(8450 AS Decimal(18, 0)), N'Pay Using Net banking')
GO
INSERT [dbo].[Tbl_ShippingDetails] ([ShippingDetailId], [MemberId], [AddressLine], [City], [State], [Country], [ZipCode], [OrderId], [AmountPaid], [PaymentType]) VALUES (3, 4, N'Karol Bagh', N'Delhi', N'New Delhi', N'India', N'110006', N'314a9d28-550d-443c-ba6b-13dc905fabaf', CAST(90850 AS Decimal(18, 0)), N'Cash On Delivery')
GO
SET IDENTITY_INSERT [dbo].[Tbl_ShippingDetails] OFF
GO
SET IDENTITY_INSERT [dbo].[Tbl_Users] ON 
GO
INSERT [dbo].[Tbl_Users] ([UserId], [FirstName], [LastName], [EmailId], [Password], [IsActive], [IsDelete], [CreatedOn], [ModifiedOn], [DOB], [GenderId], [Phoneno], [LastLogin]) VALUES (3, N'Aditi', N'Mishra', N'aditimishra@gmail.com', N'1234567890', 1, 0, CAST(N'2016-09-28T23:34:01.630' AS DateTime), CAST(N'2016-09-28T23:34:01.630' AS DateTime), CAST(N'2002-06-14' AS Date), NULL, NULL, NULL)
GO
INSERT [dbo].[Tbl_Users] ([UserId], [FirstName], [LastName], [EmailId], [Password], [IsActive], [IsDelete], [CreatedOn], [ModifiedOn], [DOB], [GenderId], [Phoneno], [LastLogin]) VALUES (4, N'Jaiganesh', N'Jaisid', N'jaiganesh@gmail.com', N'1234567890', 1, 0, CAST(N'2016-09-28T23:34:01.630' AS DateTime), CAST(N'2016-09-28T23:34:01.630' AS DateTime), NULL, NULL, NULL, NULL)
GO
INSERT [dbo].[Tbl_Users] ([UserId], [FirstName], [LastName], [EmailId], [Password], [IsActive], [IsDelete], [CreatedOn], [ModifiedOn], [DOB], [GenderId], [Phoneno], [LastLogin]) VALUES (5, N'Ayush', N'Shukla', N'ayushshukla@gmail.com', N'1234567890', 1, 0, CAST(N'2017-01-05T13:10:50.000' AS DateTime), NULL, CAST(N'2003-01-05' AS Date), NULL, NULL, NULL)
GO
INSERT [dbo].[Tbl_Users] ([UserId], [FirstName], [LastName], [EmailId], [Password], [IsActive], [IsDelete], [CreatedOn], [ModifiedOn], [DOB], [GenderId], [Phoneno], [LastLogin]) VALUES (6, N'Prince', N'Sharma', N'princesharma', N'1234567890', 1, 0, CAST(N'2018-02-14T12:45:35.000' AS DateTime), CAST(N'2018-03-15T00:00:00.000' AS DateTime), NULL, NULL, NULL, NULL)
GO
INSERT [dbo].[Tbl_Users] ([UserId], [FirstName], [LastName], [EmailId], [Password], [IsActive], [IsDelete], [CreatedOn], [ModifiedOn], [DOB], [GenderId], [Phoneno], [LastLogin]) VALUES (7, N'Prem', N'Pratap', N'prempratap@gmail.com', N'1234567890', 1, 0, CAST(N'2019-07-23T05:50:55.000' AS DateTime), CAST(N'2019-10-11T14:45:54.000' AS DateTime), CAST(N'2002-06-02' AS Date), NULL, NULL, NULL)
GO
INSERT [dbo].[Tbl_Users] ([UserId], [FirstName], [LastName], [EmailId], [Password], [IsActive], [IsDelete], [CreatedOn], [ModifiedOn], [DOB], [GenderId], [Phoneno], [LastLogin]) VALUES (8, N'Ashu', N'Varshney', N'ashuvarshey@gmail.com', N'1234567890', 1, 0, CAST(N'2020-05-17T00:00:00.000' AS DateTime), NULL, CAST(N'2000-11-29' AS Date), NULL, NULL, NULL)
GO
INSERT [dbo].[Tbl_Users] ([UserId], [FirstName], [LastName], [EmailId], [Password], [IsActive], [IsDelete], [CreatedOn], [ModifiedOn], [DOB], [GenderId], [Phoneno], [LastLogin]) VALUES (9, N'Priyanshu', N'Singh', N'priyanshusingh@gmail.com', N'0987654321', 0, 1, CAST(N'2021-07-23T12:34:50.000' AS DateTime), CAST(N'2022-06-23T23:11:12.000' AS DateTime), NULL, NULL, NULL, NULL)
GO
SET IDENTITY_INSERT [dbo].[Tbl_Users] OFF
GO
ALTER TABLE [dbo].[Tbl_Address]  WITH CHECK ADD  CONSTRAINT [FK_Tbl_Address_Tbl_Address] FOREIGN KEY([UserId])
REFERENCES [dbo].[Tbl_Users] ([UserId])
GO
ALTER TABLE [dbo].[Tbl_Address] CHECK CONSTRAINT [FK_Tbl_Address_Tbl_Address]
GO
ALTER TABLE [dbo].[Tbl_Cart]  WITH CHECK ADD  CONSTRAINT [FK__Tbl_Cart__Produc__35BCFE0A] FOREIGN KEY([ProductId])
REFERENCES [dbo].[Tbl_Product] ([ProductId])
GO
ALTER TABLE [dbo].[Tbl_Cart] CHECK CONSTRAINT [FK__Tbl_Cart__Produc__35BCFE0A]
GO
ALTER TABLE [dbo].[Tbl_Cart]  WITH CHECK ADD FOREIGN KEY([SessionId])
REFERENCES [dbo].[Tbl_Session] ([SessionId])
GO
ALTER TABLE [dbo].[Tbl_Orders]  WITH CHECK ADD  CONSTRAINT [FK_Tbl_Orders_Tbl_Payment] FOREIGN KEY([PaymentId])
REFERENCES [dbo].[Tbl_Payment] ([PaymentId])
GO
ALTER TABLE [dbo].[Tbl_Orders] CHECK CONSTRAINT [FK_Tbl_Orders_Tbl_Payment]
GO
ALTER TABLE [dbo].[Tbl_Orders]  WITH CHECK ADD  CONSTRAINT [FK_Tbl_Orders_Tbl_Product] FOREIGN KEY([ProductId])
REFERENCES [dbo].[Tbl_Product] ([ProductId])
GO
ALTER TABLE [dbo].[Tbl_Orders] CHECK CONSTRAINT [FK_Tbl_Orders_Tbl_Product]
GO
ALTER TABLE [dbo].[Tbl_Orders]  WITH CHECK ADD  CONSTRAINT [FK_Tbl_Orders_Tbl_Users] FOREIGN KEY([UserId])
REFERENCES [dbo].[Tbl_Users] ([UserId])
GO
ALTER TABLE [dbo].[Tbl_Orders] CHECK CONSTRAINT [FK_Tbl_Orders_Tbl_Users]
GO
ALTER TABLE [dbo].[Tbl_Product]  WITH CHECK ADD  CONSTRAINT [FK_Tbl_Category_Tbl_Product] FOREIGN KEY([CategoryId])
REFERENCES [dbo].[Tbl_Category] ([CategoryId])
GO
ALTER TABLE [dbo].[Tbl_Product] CHECK CONSTRAINT [FK_Tbl_Category_Tbl_Product]
GO
ALTER TABLE [dbo].[Tbl_Product]  WITH CHECK ADD  CONSTRAINT [FK_Tbl_Product_Tbl_Category] FOREIGN KEY([CategoryId])
REFERENCES [dbo].[Tbl_Category] ([CategoryId])
GO
ALTER TABLE [dbo].[Tbl_Product] CHECK CONSTRAINT [FK_Tbl_Product_Tbl_Category]
GO
ALTER TABLE [dbo].[Tbl_Session]  WITH CHECK ADD  CONSTRAINT [FK__Tbl_Sessi__UserI__6383C8BA] FOREIGN KEY([UserId])
REFERENCES [dbo].[Tbl_Users] ([UserId])
GO
ALTER TABLE [dbo].[Tbl_Session] CHECK CONSTRAINT [FK__Tbl_Sessi__UserI__6383C8BA]
GO
ALTER TABLE [dbo].[Tbl_UserPayment]  WITH CHECK ADD  CONSTRAINT [FK_Tbl_UserPayment_Tbl_Users] FOREIGN KEY([UserId])
REFERENCES [dbo].[Tbl_Users] ([UserId])
GO
ALTER TABLE [dbo].[Tbl_UserPayment] CHECK CONSTRAINT [FK_Tbl_UserPayment_Tbl_Users]
GO
/****** Object:  StoredProcedure [dbo].[Admin_Login]    Script Date: 9/26/2022 7:53:04 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[Admin_Login] 
	-- Add the parameters for the stored procedure here
	@ad_username nvarchar(50),
	@ad_password nvarchar(50)
AS
	-- SET NOCOUNT ON added to prevent extra result sets from
	-- interfering with SELECT statements.
	SET NOCOUNT ON;
	Declare @FailedCount as int
	set @FailedCount = (Select LoginFailedCount from Tbl_Admin where ad_username = @ad_username)

	if exists(Select* from Tbl_Admin where ad_username = @ad_username)
		begin
		if exists(Select* from Tbl_Admin where ad_username = @ad_username and ad_password=@ad_password)
			select 'Success' as AdminExists
		else

		update Tbl_Admin SET LoginFailedCount = @FailedCount+1 where ad_username = @ad_username

		update Tbl_Admin SET ad_lastLogin = GETDATE() where ad_username = @ad_username
			BEGIN
		IF @FailedCount >=5

		SELECT 'Maximum Attempt Reached (5 times). Your Account is Locked now.' as AdminExists
		ELSE

		SELECT CONVERT(varchar(10),(Select LoginFailedCount from Tbl_Admin where ad_username = @ad_username)) as AdminFailedcount
		end
		end
		ELSE
		BEGIN
		select 'Admin does not Exists' as AdminExists

END
GO
/****** Object:  StoredProcedure [dbo].[Categories]    Script Date: 9/26/2022 7:53:04 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[Categories] 
	-- Add the parameters for the stored procedure here
	
AS
BEGIN
	-- SET NOCOUNT ON added to prevent extra result sets from
	-- interfering with SELECT statements.
	SET NOCOUNT ON;

    -- Insert statements for procedure here
	SELECT * from Tbl_Category
END
GO
/****** Object:  StoredProcedure [dbo].[Men_List]    Script Date: 9/26/2022 7:53:04 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[Men_List] 
	-- Add the parameters for the stored procedure here
AS
BEGIN
	-- SET NOCOUNT ON added to prevent extra result sets from
	-- interfering with SELECT statements.
	SET NOCOUNT ON;

    -- Insert statements for procedure here
	SELECT ProductId,ProductName,Description,ProductImage,Price from Tbl_Product where CategoryId = 1;
end
GO
/****** Object:  StoredProcedure [dbo].[Orders]    Script Date: 9/26/2022 7:53:04 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[Orders] 
	-- Add the parameters for the stored procedure here
AS
BEGIN
	-- SET NOCOUNT ON added to prevent extra result sets from
	-- interfering with SELECT statements.
	SET NOCOUNT ON;

    -- Insert statements for procedure here
	SELECT * from Tbl_Orders
END
GO
/****** Object:  StoredProcedure [dbo].[Products]    Script Date: 9/26/2022 7:53:04 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[Products] 
	-- Add the parameters for the stored procedure here
	
AS
BEGIN
	-- SET NOCOUNT ON added to prevent extra result sets from
	-- interfering with SELECT statements.
	SET NOCOUNT ON;

    -- Insert statements for procedure here
	SELECT * from Tbl_Product
END
GO
/****** Object:  StoredProcedure [dbo].[sp_product]    Script Date: 9/26/2022 7:53:04 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[sp_product]

	-- Add the parameters for the stored procedure here
	
AS
BEGIN
	-- SET NOCOUNT ON added to prevent extra result sets from
	-- interfering with SELECT statements.
	SET NOCOUNT ON;

    -- Insert statements for procedure here
	SELECT * from Tbl_Product
END
GO
/****** Object:  StoredProcedure [dbo].[User_Login]    Script Date: 9/26/2022 7:53:04 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[User_Login] 
	-- Add the parameters for the stored procedure here
	@EmailId nvarchar(100),
	@Password nvarchar(50)
AS
BEGIN
	-- SET NOCOUNT ON added to prevent extra result sets from
	-- interfering with SELECT statements.
	SET NOCOUNT ON;

	if exists(Select* from Tbl_Users where EmailId = @EmailId)
		begin
		if exists(Select* from Tbl_Users where EmailId = @EmailId and Password=@Password)
			select 'Success' as UserExists
			
		else

			update Tbl_Users SET LastLogin = GETDATE() where EmailId = @EmailId
		end
		ELSE
		BEGIN
		select 'User does not Exists' as UserExists
		end

END
GO
/****** Object:  StoredProcedure [dbo].[Users]    Script Date: 9/26/2022 7:53:04 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[Users]
	-- Add the parameters for the stored procedure here
	
AS
BEGIN
	-- SET NOCOUNT ON added to prevent extra result sets from
	-- interfering with SELECT statements.
	SET NOCOUNT ON;

    -- Insert statements for procedure here
	SELECT * FROM Tbl_Users
END
GO
/****** Object:  StoredProcedure [dbo].[USP_MemberShoppingCartDetails]    Script Date: 9/26/2022 7:53:04 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE proc [dbo].[USP_MemberShoppingCartDetails] 
(@memberId int) 
as 
begin 
select cr.CartId, p.Price,p.ProductId,p.ProductImage,p.ProductName,c.CategoryName 
from Tbl_Cart cr join Tbl_Product p on p.ProductId=cr.ProductId 
join Tbl_Category c on c.CategoryId=p.CategoryId 
join Tbl_Members m on m.MemberId=cr.MemberId where m.MemberId=@memberId 
and cr.CartStatusId=1 end 
GO
/****** Object:  StoredProcedure [dbo].[USP_Search]    Script Date: 9/26/2022 7:53:04 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
Create proc [dbo].[USP_Search](@searchKey varchar(100)) as begin select p.Description,p.Price,p.ProductId,p.ProductImage, p.ProductName, c.CategoryName from Tbl_Product p  join Tbl_Category c on p.CategoryId=c.CategoryId where p.IsActive=1 and p.IsDelete=0 and c.IsActive=1 and c.IsDelete=0 and (p.ProductName like '%'+@searchKey+'%' or c.CategoryName like '%'+@searchKey+'%') end

GO
/****** Object:  StoredProcedure [dbo].[Women_List]    Script Date: 9/26/2022 7:53:04 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[Women_List] 
	-- Add the parameters for the stored procedure here
AS
BEGIN
	-- SET NOCOUNT ON added to prevent extra result sets from
	-- interfering with SELECT statements.
	SET NOCOUNT ON;

    -- Insert statements for procedure here
	SELECT ProductId,ProductName,Description,ProductImage,Price from Tbl_Product where CategoryId = 2;
end
GO
USE [master]
GO
ALTER DATABASE [online_shopping] SET  READ_WRITE 
GO
