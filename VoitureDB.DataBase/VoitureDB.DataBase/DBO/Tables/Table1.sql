CREATE TABLE [dbo].[Voiture]
(
	[Id] INT NOT NULL PRIMARY KEY IDENTITY,
	[RegistrationNumber] nvarchar(200) not null,
	[Color] NVARCHAR(50) NOT NULL,
	[Mileage] INT NOT NULL,
	[EnginePower] int NOT NULL,
	[Brand]	NVARCHAR(200) NOT NULL,
	[Model] NVARCHAR(200) NOT NULL,
	[ArrivalDateTime] DATETIME NOT NULL,
	[DoorCount] INT NOT NULL,
	[SeatCount] INT NOT NULL,
	[RentalRange] NVARCHAR(200) NOT NULL,
	[RentalBasePricePerDay] BIGINT NOT NULL	

)
