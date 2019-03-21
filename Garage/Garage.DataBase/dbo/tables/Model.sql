CREATE TABLE [dbo].[Model] 
(
    [Identifier]            INT            IDENTITY (1, 1) NOT NULL,
    [Name]                  NVARCHAR (100) NOT NULL,
    [DoorCount]             INT            NOT NULL,
    [SeatCount]             INT            NOT NULL,
    [IdentifierRentalRange] INT            NOT NULL,
    [IdentifierBrand]       INT            NOT NULL,
    CONSTRAINT [PK_Model] PRIMARY KEY CLUSTERED ([Identifier] ASC),
    CONSTRAINT [FK_Model_Brand] FOREIGN KEY ([IdentifierBrand]) REFERENCES [dbo].[Brand] ([Identifier]),
    CONSTRAINT [FK_Model_RentalRange] FOREIGN KEY ([IdentifierRentalRange]) REFERENCES [dbo].[RentalRange] ([Identifier])
);