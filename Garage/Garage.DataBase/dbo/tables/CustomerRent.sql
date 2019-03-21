﻿--CREATE TABLE [dbo].[CustomerRent] 
--(
--    [IdentifierCustomer] INT NOT NULL,
--    [IdentifierRent]     INT NOT NULL,
--    CONSTRAINT [PK_CustomerRent] PRIMARY KEY CLUSTERED ([IdentifierCustomer] ASC, [IdentifierRent] ASC),
--    CONSTRAINT [FK_CustomerRent_Customer] FOREIGN KEY ([IdentifierCustomer]) REFERENCES [dbo].[Customer] ([Identifier]) ON DELETE CASCADE ON UPDATE CASCADE,
--    CONSTRAINT [FK_CustomerRent_Rent] FOREIGN KEY ([IdentifierRent]) REFERENCES [dbo].[Rent] ([Identifier]) ON DELETE CASCADE ON UPDATE CASCADE
--);