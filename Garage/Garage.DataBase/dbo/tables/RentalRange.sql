CREATE TABLE [dbo].[RentalRange] 
(
    [Identifier] INT           IDENTITY (1, 1) NOT NULL,
    [Label]      NVARCHAR (50) NOT NULL,
    CONSTRAINT [PK_RentalRange] PRIMARY KEY CLUSTERED ([Identifier] ASC)
);