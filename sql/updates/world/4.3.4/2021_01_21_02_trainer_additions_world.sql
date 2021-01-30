-- Insert gossip menu options to low level trainers with no options using generic text.
DELETE FROM `gossip_menu_option` WHERE `OptionIndex` IN (0,1,2) AND `MenuId` IN (14137,14141,14140,10879,14138,11645,11831,10702,10675,11185,10686,10985,14139,11617);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcflag`, `VerifiedBuild`) VALUES
(14137,0,3,'I require training.', 2756, 5, 16, 0),
(14137,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(14137,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(14141,0,3,'I require training.', 2756, 5, 16, 0),
(14141,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(14141,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(14140,0,3,'I require training.', 2756, 5, 16, 0),
(14140,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(14140,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(10879,0,3,'I require training.', 2756, 5, 16, 0),
(10879,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(10879,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(14138,0,3,'I require training.', 2756, 5, 16, 0),
(14138,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(14138,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(11645,0,3,'I require training.', 2756, 5, 16, 0),
(11645,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(11645,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(11831,0,3,'I require training.', 2756, 5, 16, 0),
(11831,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(11831,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(10702,0,3,'I require training.', 2756, 5, 16, 0),
(10702,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(10702,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(10675,0,3,'I require training.', 2756, 5, 16, 0),
(10675,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(10675,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(11185,0,3,'I require training.', 2756, 5, 16, 0),
(11185,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(11185,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(10686,0,3,'I require training.', 2756, 5, 16, 0),
(10686,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(10686,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(10985,0,3,'I require training.', 2756, 5, 16, 0),
(10985,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(10985,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(14139,0,3,'I require training.', 2756, 5, 16, 0),
(14139,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(14139,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(11617,0,3,'I require training.', 2756, 5, 16, 0),
(11617,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(11617,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0);

-- Insert gossip menu options to warrior trainers with no options using generic text.
DELETE FROM `gossip_menu_option` WHERE `OptionIndex` IN (0,1,2) AND `MenuId` IN (11052,12513,12532,12533,12925);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcflag`, `VerifiedBuild`) VALUES
(11052,0,3,'I require training.', 2756, 5, 16, 0),
(11052,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(11052,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(12513,0,3,'I require training.', 2756, 5, 16, 0),
(12513,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(12513,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(12532,0,3,'I require training.', 2756, 5, 16, 0),
(12532,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(12532,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(12533,0,3,'I require training.', 2756, 5, 16, 0),
(12533,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(12533,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(12925,0,3,'I require training.', 2756, 5, 16, 0),
(12925,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(12925,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0);

-- Insert gossip menu options to paladin trainers with no options using generic text.
DELETE FROM `gossip_menu_option` WHERE `OptionIndex` IN (0,1,2) AND `MenuId` IN (12926);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcflag`, `VerifiedBuild`) VALUES
(12926,0,3,'I require training.', 2756, 5, 16, 0),
(12926,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(12926,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0);

-- Insert gossip menu options to hunter trainers with no options using generic text.
DELETE FROM `gossip_menu_option` WHERE `OptionIndex` IN (0,1,2) AND `MenuId` IN (14144,10549,10814,11045,10697,12528,12535,12924);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcflag`, `VerifiedBuild`) VALUES
(14144,0,3,'I require training.', 2756, 5, 16, 0),
(14144,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(14144,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(10549,0,3,'I require training.', 2756, 5, 16, 0),
(10549,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(10549,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(10814,0,3,'I require training.', 2756, 5, 16, 0),
(10814,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(10814,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(11045,0,3,'I require training.', 2756, 5, 16, 0),
(11045,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(11045,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(10697,0,3,'I require training.', 2756, 5, 16, 0),
(10697,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(10697,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(12528,0,3,'I require training.', 2756, 5, 16, 0),
(12528,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(12528,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(12535,0,3,'I require training.', 2756, 5, 16, 0),
(12535,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(12535,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(12924,0,3,'I require training.', 2756, 5, 16, 0),
(12924,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(12924,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0);

-- Insert gossip menu options to rogue trainers with no options using generic text.
DELETE FROM `gossip_menu_option` WHERE `OptionIndex` IN (0,1,2) AND `MenuId` IN (12517,10554,10819,10843,11051,11621,10699,12051,12524,12531,12536,12928,12543,12564);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcflag`, `VerifiedBuild`) VALUES
(12517,0,3,'I require training.', 2756, 5, 16, 0),
(12517,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(12517,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(10554,0,3,'I require training.', 2756, 5, 16, 0),
(10554,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(10554,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(10819,0,3,'I require training.', 2756, 5, 16, 0),
(10819,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(10819,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(10843,0,3,'I require training.', 2756, 5, 16, 0),
(10843,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(10843,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(11051,0,3,'I require training.', 2756, 5, 16, 0),
(11051,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(11051,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(11621,0,3,'I require training.', 2756, 5, 16, 0),
(11621,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(11621,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(10699,0,3,'I require training.', 2756, 5, 16, 0),
(10699,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(10699,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(12051,0,3,'I require training.', 2756, 5, 16, 0),
(12051,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(12051,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(12524,0,3,'I require training.', 2756, 5, 16, 0),
(12524,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(12524,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(12531,0,3,'I require training.', 2756, 5, 16, 0),
(12531,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(12531,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(12536,0,3,'I require training.', 2756, 5, 16, 0),
(12536,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(12536,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(12928,0,3,'I require training.', 2756, 5, 16, 0),
(12928,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(12928,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(12543,0,3,'I require training.', 2756, 5, 16, 0),
(12543,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(12543,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(12564,0,3,'I require training.', 2756, 5, 16, 0),
(12564,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(12564,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0);

-- Insert gossip menu options to priest trainers with no options using generic text.
DELETE FROM `gossip_menu_option` WHERE `OptionIndex` IN (0,1,2) AND `MenuId` IN (4560,10553,10818,11050,12004,12841);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcflag`, `VerifiedBuild`) VALUES
(4560,0,3,'I require training.', 2756, 5, 16, 0),
(4560,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(4560,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(10553,0,3,'I require training.', 2756, 5, 16, 0),
(10553,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(10553,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(10818,0,3,'I require training.', 2756, 5, 16, 0),
(10818,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(10818,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(11050,0,3,'I require training.', 2756, 5, 16, 0),
(11050,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(11050,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(12004,0,3,'I require training.', 2756, 5, 16, 0),
(12004,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(12004,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(12841,0,3,'I require training.', 2756, 5, 16, 0),
(12841,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(12841,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0);

-- Insert gossip menu options to shaman trainers with no options using generic text.
DELETE FROM `gossip_menu_option` WHERE `OptionIndex` IN (0,1,2) AND `MenuId` IN (11049);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcflag`, `VerifiedBuild`) VALUES
(11049,0,3,'I require training.', 2756, 5, 16, 0),
(11049,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(11049,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0);
 
-- Insert gossip menu options to mage trainers with no options using generic text.
DELETE FROM `gossip_menu_option` WHERE `OptionIndex` IN (0,1,2) AND `MenuId` IN (10551,10816,10878,11620,11810,12572,12049,12525,14136);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcflag`, `VerifiedBuild`) VALUES
(10551,0,3,'I require training.', 2756, 5, 16, 0),
(10551,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(10551,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(10878,0,3,'I require training.', 2756, 5, 16, 0),
(10878,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(10878,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(11620,0,3,'I require training.', 2756, 5, 16, 0),
(11620,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(11620,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(10816,0,3,'I require training.', 2756, 5, 16, 0),
(10816,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(10816,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(11810,0,3,'I require training.', 2756, 5, 16, 0),
(11810,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(11810,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(12572,0,3,'I require training.', 2756, 5, 16, 0),
(12572,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(12572,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(12049,0,3,'I require training.', 2756, 5, 16, 0),
(12049,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(12049,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(12525,0,3,'I require training.', 2756, 5, 16, 0),
(12525,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(12525,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(14136,0,3,'I require training.', 2756, 5, 16, 0),
(14136,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(14136,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0);

-- Insert gossip menu options to warlock trainers with no options using generic text.
DELETE FROM `gossip_menu_option` WHERE `OptionIndex` IN (0,1,2) AND `MenuId` IN (10840,12053,4608,12526,12921,4602,12882,2522,12845);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcflag`, `VerifiedBuild`) VALUES
(10840,0,3,'I require training.', 2756, 5, 16, 0),
(10840,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(10840,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(12053,0,3,'I require training.', 2756, 5, 16, 0),
(12053,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(12053,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(4608,0,3,'I require training.', 2756, 5, 16, 0),
(4608,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(4608,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(12526,0,3,'I require training.', 2756, 5, 16, 0),
(12526,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(12526,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(12921,0,3,'I require training.', 2756, 5, 16, 0),
(12921,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(12921,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(4602,0,3,'I require training.', 2756, 5, 16, 0),
(4602,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(4602,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(12882,0,3,'I require training.', 2756, 5, 16, 0),
(12882,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(12882,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(2522,0,3,'I require training.', 2756, 5, 16, 0),
(2522,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(2522,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(12845,0,3,'I require training.', 2756, 5, 16, 0),
(12845,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(12845,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0);

-- Insert gossip menu options to druid trainers with no options using generic text.
DELETE FROM `gossip_menu_option` WHERE `OptionIndex` IN (0,1,2) AND `MenuId` IN (10373,11997);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcflag`, `VerifiedBuild`) VALUES
(10373,0,3,'I require training.', 2756, 5, 16, 0),
(10373,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(10373,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0),
(11997,0,3,'I require training.', 2756, 5, 16, 0),
(11997,1,0,'I wish to unlearn my talents.',62295,16,16,0),
(11997,2,0,'I wish to know about Dual Talent Specialization.',33762,20,1,0);

-- Insert gossip menu options to portal trainers with no options using generic text.
DELETE FROM `gossip_menu_option` WHERE `OptionIndex` IN (0) AND `MenuId` IN (11972);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcflag`, `VerifiedBuild`) VALUES
(11972,0,3,'I require training.', 2756, 5, 16, 0);

-- Insert gossip menu options to alchemy trainers with no options using generic text.
DELETE FROM `gossip_menu_option` WHERE `OptionIndex` IN (0) AND `MenuId` IN (4117,8863);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcflag`, `VerifiedBuild`) VALUES
(4117,0,3,'Train me.', 3266, 5, 16, 0),
(8863,0,3,'Train me.', 3266, 5, 16, 0);

-- Insert gossip menu options to blacksmithing trainers with no options using generic text.
DELETE FROM `gossip_menu_option` WHERE `OptionIndex` IN (0) AND `MenuId` IN (2749,1041,9131,9132,8254);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcflag`, `VerifiedBuild`) VALUES
(2749,0,3,'Train me.', 3266, 5, 16, 0),
(1041,0,3,'Train me.', 3266, 5, 16, 0),
(9131,0,3,'Train me.', 3266, 5, 16, 0),
(9132,0,3,'Train me.', 3266, 5, 16, 0),
(8254,0,3,'Train me.', 3266, 5, 16, 0);

-- Insert gossip menu options to enchanting trainers with no options using generic text.
DELETE FROM `gossip_menu_option` WHERE `OptionIndex` IN (0) AND `MenuId` IN (4169,4171,4170);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcflag`, `VerifiedBuild`) VALUES
(4169,0,3,'Train me.', 3266, 5, 16, 0),
(4171,0,3,'Train me.', 3266, 5, 16, 0),
(4170,0,3,'Train me.', 3266, 5, 16, 0);

-- Insert gossip menu options to engineering trainers with no options using generic text.
DELETE FROM `gossip_menu_option` WHERE `OptionIndex` IN (0) AND `MenuId` IN (4136,1467,1469,1465,7512,7513,10363);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcflag`, `VerifiedBuild`) VALUES
(4136,0,3,'Train me.', 3266, 5, 16, 0),
(1467,0,3,'Train me.', 3266, 5, 16, 0),
(1469,0,3,'Train me.', 3266, 5, 16, 0),
(1465,0,3,'Train me.', 3266, 5, 16, 0),
(7512,0,3,'Train me.', 3266, 5, 16, 0),
(7513,0,3,'Train me.', 3266, 5, 16, 0),
(10363,0,3,'Train me.', 3266, 5, 16, 0);

-- Insert gossip menu options to leatherworking trainers with no options using generic text.
DELETE FROM `gossip_menu_option` WHERE `OptionIndex` IN (0) AND `MenuId` IN (4208,4842,4244);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcflag`, `VerifiedBuild`) VALUES
(4208,0,3,'Train me.', 3266, 5, 16, 0),
(4842,0,3,'Train me.', 3266, 5, 16, 0),
(4244,0,3,'Train me.', 3266, 5, 16, 0);

-- Insert gossip menu options to tailoring trainers with no options using generic text.
DELETE FROM `gossip_menu_option` WHERE `OptionIndex` IN (0) AND `MenuId` IN (10138);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcflag`, `VerifiedBuild`) VALUES
(10138,0,3,'Train me.', 3266, 5, 16, 0);

-- Insert gossip menu options to first aid trainers with no options using generic text.
DELETE FROM `gossip_menu_option` WHERE `OptionIndex` IN (0) AND `MenuId` IN (8522);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcflag`, `VerifiedBuild`) VALUES
(8522,0,3,'Train me.', 3266, 5, 16, 0);

-- Correct existing creature_trainer records
UPDATE `creature_trainer` SET `MenuId` = 14141 WHERE `CreatureId` = 15513;
UPDATE `creature_trainer` SET `MenuId` = 14140 WHERE `CreatureId` = 15285;
UPDATE `creature_trainer` SET `MenuId` = 10373 WHERE `CreatureId` = 4219;

UPDATE `creature_trainer` SET `MenuId` = 10138 WHERE `CreatureId` = 28699;

-- add `creature_trainer` records for low level paladin trainers.
DELETE FROM `creature_trainer` WHERE `CreatureId` IN (15280);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES 
(15280,168,14137,0);

-- add `creature_trainer` records for low level hunter trainers.
DELETE FROM `creature_trainer` WHERE `CreatureId` IN (34673,35874,39214);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES 
(34673,15,10675,0),
(35874,15,10697,0),
(39214,15,11185,0);

-- add `creature_trainer` records for low level rogue trainers.
DELETE FROM `creature_trainer` WHERE `CreatureId` IN (34693,35871,38244);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES 
(34693,17,10686,0),
(35871,33,10699,0),
(38244,17,10985,0);

-- add `creature_trainer` records for low level shaman trainers.
DELETE FROM `creature_trainer` WHERE `CreatureId` IN (37115);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES
(37115,134,10879,0);

-- add `creature_trainer` records for low level priest trainers.
DELETE FROM `creature_trainer` WHERE `CreatureId` IN (15284,42323);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES 
(15284,127,14139,0),
(42323,127,11617,0);

-- add `creature_trainer` records for low level mage trainers.
DELETE FROM `creature_trainer` WHERE `CreatureId` IN (15279,37121,42331,43006);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES 
(15279,135,14136,0),
(37121,135,10878,0),
(42331,135,11620,0),
(43006,135,11810,0);

-- add `creature_trainer` records for low level warlock trainers.
DELETE FROM `creature_trainer` WHERE `CreatureId` IN (15283,35869,42618,43455);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES 
(15283,32,14138,0),
(35869,32,10702,0),
(42618,32,11645,0),
(43455,32,11831,0);

-- add `creature_trainer` records for warrior trainers.
DELETE FROM `creature_trainer` WHERE `CreatureId` IN (38518,42366,49736,49902,49923,50018,50155,50500);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES 
(38518,16,11052,0),
(42366,33,11621,0),
(49736,16,12513,0),
(49902,16,12532,0),
(49923,16,12533,0),
(50018,16,12925,0),
(50155,16,12533,0),
(50500,16,12513,0);

-- add `creature_trainer` records for paladin trainers.
DELETE FROM `creature_trainer` WHERE `CreatureId` IN (50012);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES 
(50012,164,12926,0);

-- add `creature_trainer` records for hunter trainers.
DELETE FROM `creature_trainer` WHERE `CreatureId` IN (4892,16270,35758,36518,38122,44461,49806,49927,50007,50157);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES 
(4892,40,12835,0),
(16270,40,14144,0),
(35758,40,10549,0),
(36518,40,10814,0),
(38122,40,11045,0),
(44461,40,10697,0),
(49806,40,12528,0),
(49927,40,12535,0),
(50007,40,12924,0),
(50157,40,12535,0);

-- add `creature_trainer` records for rogue trainers.
DELETE FROM `creature_trainer` WHERE `CreatureId` IN (23566,35806,36524,36630,38517,38796,44464,45717,49745,49782,49870,49939,50016,50027,50127,50158,50498);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES 
(23566,33,12517,0),
(35806,33,10554,0),
(36524,33,10819,0),
(36630,33,10843,0),
(38517,33,11051,0),
(38796,33,10843,0),
(44464,33,10699,0),
(45717,33,12051,0),
(49745,33,12517,0),
(49782,33,12524,0),
(49870,33,12531,0),
(49939,33,12536,0),
(50016,33,12928,0),
(50027,33,12543,0),
(50127,33,12564,0),
(50158,33,12536,0),
(50498,33,12517,0);

-- add `creature_trainer` records for priest trainers.
DELETE FROM `creature_trainer` WHERE `CreatureId` IN (5143,35805,36523,38516,45306,53403);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES 
(5143,3,4560,0),
(35805,3,10553,0),
(36523,3,10818,0),
(38516,3,11050,0),
(45306,3,12004,0),
(53403,3,12841,0);

-- add `creature_trainer` records for shaman trainers.
DELETE FROM `creature_trainer` WHERE `CreatureId` IN (38515);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES 
(38515,124,11049,0);

-- add `creature_trainer` records for mage trainers.
DELETE FROM `creature_trainer` WHERE `CreatureId` IN (35780,36520,38514,45714,49786,49896);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES 
(35780,135,10551,0),
(36520,135,10816,0),
(38514,135,12572,0),
(45714,135,12049,0),
(49786,135,12525,0),
(49896,135,12049,0);

-- add `creature_trainer` records for warlock trainers.
DELETE FROM `creature_trainer` WHERE `CreatureId` IN (36652,38797,43892,45720,48612,49718,49791,49895,50017,50028,50502,50732,53404);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES 
(36652,154,10840,0),
(38797,154,10840,0),
(43892,154,12821,0),
(45720,154,12053,0),
(48612,154,4608,0),
(49718,154,4608,0),
(49791,154,12526,0),
(49895,154,12053,0),
(50017,154,12921,0),
(50028,154,4602,0),
(50502,154,12882,0),
(50732,154,2522,0),
(53404,154,12845,0);

-- add `creature_trainer` records for druid trainers.
DELETE FROM `creature_trainer` WHERE `CreatureId` IN (13476);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES
(13476,39,11997,0);

-- add `creature_trainer` records for portal trainers.
DELETE FROM `creature_trainer` WHERE `CreatureId` IN (45139);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES
(45139,149,11972,0);

-- add `creature_trainer` records for alchemy trainers.
DELETE FROM `creature_trainer` WHERE `CreatureId` IN (3964,16723);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES
(3964,122,4117,0),
(16723,122,8863,0);

-- add `creature_trainer` records for blacksmithing trainers.
DELETE FROM `creature_trainer` WHERE `CreatureId` IN (3557,7232,16583,19341,20124,20125,21209);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES
(3557,58,2749,0),
(7232,58,1041,0),
(16583,58,8760,0),
(19341,58,7809,0),
(20124,58,9131,0),
(20125,58,9132,0),
(21209,58,8254,0);

-- add `creature_trainer` records for enchanting trainers.
DELETE FROM `creature_trainer` WHERE `CreatureId` IN (11072,11073,11074);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES
(11072,62,4169,0),
(11073,62,4171,0),
(11074,62,4170,0);

-- add `creature_trainer` records for engineering trainers.
DELETE FROM `creature_trainer` WHERE `CreatureId` IN (3290,7406,8126,8738,17634,17637,18775,33634,33677);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES
(3290,407,4136,0),
(7406,407,1467,0),
(8126,407,1469,0),
(8738,407,1465,0),
(17634,407,7512,0),
(17637,407,7513,0),
(18775,407,7820,0),
(33634,407,10363,0),
(33677,407,10363,0);

-- add `creature_trainer` records for leatherworking trainers.
DELETE FROM `creature_trainer` WHERE `CreatureId` IN (1385,8153,11098);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES
(1385,56,4208,0),
(8153,56,4842,0),
(11098,56,4244,0);

-- add `creature_trainer` records for tailoring trainers.
DELETE FROM `creature_trainer` WHERE `CreatureId` IN (28699);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES
(28699,163,10138,0);

-- add `creature_trainer` records for first aid trainers.
DELETE FROM `creature_trainer` WHERE `CreatureId` IN (19184,22477);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES
(19184,107,8522,0),
(22477,107,8522,0);