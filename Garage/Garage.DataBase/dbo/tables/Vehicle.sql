CREATE TABLE [dbo].[Vehicle] 
(
    [Identifier]         INT           IDENTITY (1, 1) NOT NULL,
    [Color]              NVARCHAR (50) NOT NULL,
    [RegistrationNumber] NVARCHAR (10) NOT NULL,
    [Mileage]            INT           NOT NULL,
    [ArrivalDate]        DATE          NOT NULL,
    [IdentifierModel]    INT           NOT NULL,
    CONSTRAINT [PK_Vehicle] PRIMARY KEY CLUSTERED ([Identifier] ASC),
    CONSTRAINT [FK_Vehicle_Model] FOREIGN KEY ([IdentifierModel]) REFERENCES [dbo].[Model] ([Identifier])
);