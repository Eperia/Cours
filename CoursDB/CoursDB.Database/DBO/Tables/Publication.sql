CREATE TABLE [dbo].[Publication]
(
	[Identifier] INT NOT NULL PRIMARY KEY IDENTITY,
	[Title]	NVARCHAR(200) NOT NULL,
	[StartDate] DATE NOT NULL,
	[EndDate] DATE NOT NULL,
	[Description] NVARCHAR(4000) NOT NULL,
	[IdentifierPublisher] INT NOT NULL,
	CONSTRAINT [FK_Publication_Publishert] FOREIGN KEY ([IdentifierPublisher]) REFERENCES [dbo].[Publisher]
)
