CREATE TABLE [dbo].[Rent] 
(
    [Identifier]          INT            IDENTITY (1, 1) NOT NULL,
    [StartDate]           DATE           NOT NULL,
    [EndDate]             DATE           NOT NULL,
    [DriverFirstName]     NVARCHAR (100) NOT NULL,
    [DriverLastName]      NVARCHAR (100) NOT NULL,
    [DriverLicenceNumber] NVARCHAR (20)  NOT NULL,
    [IdentifierVehicle]   INT            NOT NULL,
    CONSTRAINT [PK_Rent] PRIMARY KEY CLUSTERED ([Identifier] ASC),
    CONSTRAINT [FK_Rent_Vehicle] FOREIGN KEY ([IdentifierVehicle]) REFERENCES [dbo].[Vehicle] ([Identifier]) ON DELETE CASCADE ON UPDATE CASCADE
);