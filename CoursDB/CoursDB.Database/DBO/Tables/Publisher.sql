﻿CREATE TABLE [dbo].[Publisher]
(
	[Id] INT NOT NULL PRIMARY KEY IDENTITY,
	[Name] NVARCHAR(200) NOT NULL,
	[WebSite] NVARCHAR(200) NULL,
	[MaxPublication] INT NOT NULL
)