-- MySQL dump 10.13  Distrib 5.5.46, for debian-linux-gnu (x86_64)
--
-- Host: 0.0.0.0    Database: psexec
-- ------------------------------------------------------
-- Server version	5.5.46-0ubuntu0.14.04.2

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `builds`
--

DROP TABLE IF EXISTS `builds`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `builds` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `country_code` char(2) NOT NULL DEFAULT 'SG',
  `postal_code` varchar(20) NOT NULL,
  `place_name` varchar(180) NOT NULL,
  `admin_name1` varchar(100) NOT NULL,
  `admin_code1` varchar(20) NOT NULL,
  `admin_name2` varchar(100) NOT NULL,
  `admin_code2` varchar(20) NOT NULL,
  `admin_name3` varchar(100) NOT NULL,
  `admin_code3` varchar(20) NOT NULL,
  `latitude` decimal(7,4) NOT NULL DEFAULT '1.3500',
  `longitude` decimal(7,4) NOT NULL DEFAULT '103.8300',
  `accuracy` tinyint(4) NOT NULL DEFAULT '1',
  `img_name` char(50) NOT NULL,
  `building` varchar(20) NOT NULL,
  `yearstart` int(4) NOT NULL DEFAULT '1900',
  `freelease` varchar(30) NOT NULL,
  `sqft` int(5) NOT NULL DEFAULT '1',
  `bedroom` int(2) NOT NULL DEFAULT '0',
  `shower` int(2) NOT NULL DEFAULT '0',
  `price` int(10) NOT NULL DEFAULT '1',
  `description` varchar(500) NOT NULL,
  `user_id` int(5) NOT NULL DEFAULT '1',
  PRIMARY KEY (`id`),
  KEY `place_name` (`place_name`),
  KEY `admin_name1` (`admin_name1`),
  KEY `postal_code` (`postal_code`),
  FULLTEXT KEY `MyIndex` (`postal_code`,`place_name`,`admin_name1`)
) ENGINE=MyISAM AUTO_INCREMENT=39 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `builds`
--

LOCK TABLES `builds` WRITE;
/*!40000 ALTER TABLE `builds` DISABLE KEYS */;
INSERT INTO `builds` VALUES (2,'SG','018936','Marina One','7 Straits View','','MARINA ONE EAST TOWER','','','',1.2798,103.8536,1,'IMG_0751.JPG','Condominium',2017,'99years Leasehold',1518,3,5,3333000,'Marina One is strategically located in the heart of the new Marina Bay financial district, \r\nand it is an integrated development comprising luxury residence units, office space and retail shops. \r\nIt is a rare mixed development site situated in CBD which offers owners and investors great potential for future growth.',1),(3,'SG','338520','Eight Riversuites','8 Whampoa East','','Eight Riversuites','','','',1.3214,103.8640,1,'38eightriversuites.JPG','Cluster House',2016,'99years Leasehold',2960,3,3,2200000,'Eight Riversuites is a 99-Year Leasehold Apartment located at Whampoa East in District 12. It comprises of 862 Units. Eight Riversuites is close to Boon Keng MRT (NE9), Potong Pasir MRT (NE10) and Kallang MRT (EW10). It is due to be completed in 2016. Schools close to Eight Riversuites include Bendemeer Primary School, Bendemeer Secondary School, St Andrew’s Junior School and St Andrews Junior College.',1),(4,'SG','786020','The Brooks I','60 Springside Walk','','The Brooks','','','',1.4052,103.8200,1,'73springside_alvin.JPG','Condominium',2017,'Freehold',1152,2,2,1499000,'Potential Tenant Base for Rental Growth: - Upcoming Regional and Fringe Centres. Eg Woodlands Regional Centre and Selatar Regional Centre. - Expanded Retail option eg. Sembawang Shopping Centre, Causeway Point and North Point etc. - New Sembawang Integrated Club - Enhancing Transportation linkage and accessibility in North Region. Eg. Upcoming Thomson Line (TSL) and North-South Expressway (NSE) ',1),(5,'SG','439853','Amber Skye','8 Amber Road','','Amber Skye','','','',1.2994,103.8983,1,'161springside_alvin.JPG','Condominium',2017,'Freehold',990,2,2,1800000,'Amber Skye is a freehold development located at 8 Amber Road, Singapore 439853, in District 15, minutes walk away from Dakota MRT Station. Amber Skye is close to East Coast Park and East Shore Hospital. The upcoming Amber MRT station will have its exit/entrance next to Amber Skye. ',1),(6,'SG','128807','The Trilinq','28 Jalan Lempeng','','The Trilinq','','','',1.3179,103.7615,1,'163springside_alvin.JPG','Condominium',2017,'99years Leasehold',1109,2,2,1268000,'',1);
/*!40000 ALTER TABLE `builds` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `places`
--

DROP TABLE IF EXISTS `places`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `places` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `country_code` char(2) NOT NULL,
  `postal_code` varchar(20) NOT NULL,
  `place_name` varchar(180) NOT NULL,
  `admin_name1` varchar(100) NOT NULL,
  `admin_code1` varchar(20) NOT NULL,
  `admin_name2` varchar(100) NOT NULL,
  `admin_code2` varchar(20) NOT NULL,
  `admin_name3` varchar(100) NOT NULL,
  `admin_code3` varchar(20) NOT NULL,
  `latitude` decimal(7,4) NOT NULL,
  `longitude` decimal(7,4) NOT NULL,
  `accuracy` tinyint(4) NOT NULL,
  PRIMARY KEY (`id`),
  FULLTEXT KEY `place_name` (`place_name`),
  FULLTEXT KEY `postal_code` (`postal_code`),
  FULLTEXT KEY `admin_name1` (`admin_name1`),
  FULLTEXT KEY `admin_name2` (`admin_name2`),
  FULLTEXT KEY `psexec_index` (`place_name`,`postal_code`,`admin_name1`,`admin_name2`)
) ENGINE=MyISAM AUTO_INCREMENT=40993 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `places`
--

LOCK TABLES `places` WRITE;
/*!40000 ALTER TABLE `places` DISABLE KEYS */;
INSERT INTO `places` VALUES (40976,'SG','018936','Marina One','7 Straits View','','MARINA ONE EAST TOWER','','','',1.2798,103.8536,4),(40981,'SG','338520','Eight Riversuites','8 Whampoa East','','Eight Riversuites','','','',1.3214,103.8640,4),(40982,'SG','786020','The Brooks I','60 Springside Walk','','The Brooks','','','',1.4052,103.8200,4),(40983,'SG','439853','Amber Skye','8 Amber Road','','Amber Skye','','','',1.2994,103.8983,4),(40984,'SG','128807','The Trilinq','28 Jalan Lempeng','','The Trilinq','','','',1.3179,103.7615,4);
/*!40000 ALTER TABLE `places` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `users`
--

DROP TABLE IF EXISTS `users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `users` (
  `id` int(5) NOT NULL AUTO_INCREMENT,
  `username` varchar(255) NOT NULL,
  `hash` varchar(255) NOT NULL,
  `cash` decimal(65,4) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `username` (`username`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `users`
--

LOCK TABLES `users` WRITE;
/*!40000 ALTER TABLE `users` DISABLE KEYS */;
INSERT INTO `users` VALUES (1,'JJLin','$2y$10$PWB6QCfQDjpHoIO1vi2XSu6Uwwf.DUhFuGrLGplMw2KQwaU7dLJuG',13025.6000);
/*!40000 ALTER TABLE `users` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2016-12-12 17:09:17
