CREATE TABLE [dbo].[Brand]
(
    [Identifier] INT            IDENTITY (1, 1) NOT NULL,
    [Name]       NVARCHAR (100) NOT NULL,
    CONSTRAINT [PK_Brand] PRIMARY KEY CLUSTERED ([Identifier] ASC)
);