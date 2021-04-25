-- MySQL dump 10.13  Distrib 5.5.46, for debian-linux-gnu (x86_64)
--
-- Host: 0.0.0.0    Database: pset7
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
-- Table structure for table `history`
--

DROP TABLE IF EXISTS `history`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `history` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `user_id` int(5) NOT NULL,
  `buysell` int(1) NOT NULL,
  `datetime` datetime NOT NULL,
  `symbol` char(8) NOT NULL,
  `shares` int(10) NOT NULL,
  `price` decimal(10,4) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=45 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `history`
--

LOCK TABLES `history` WRITE;
/*!40000 ALTER TABLE `history` DISABLE KEYS */;
INSERT INTO `history` VALUES (20,9,0,'2016-08-11 04:14:55','AAPL',10,108.0000),(21,9,0,'2016-08-11 04:16:46','BABA',20,87.3300),(22,9,0,'2016-08-11 04:17:04','FB',10,124.8800),(23,9,0,'2016-08-11 04:17:26','GOOG',2,784.6800),(24,9,0,'2016-08-11 04:17:45','YHOO',30,39.9300),(25,9,0,'2016-08-11 04:18:15','ME8U.SI',100,1.7650),(26,9,0,'2016-08-11 04:18:38','U11.SI',100,17.8300),(27,9,1,'2016-08-11 04:20:11','U11.SI',100,17.8300),(28,9,0,'2016-08-11 04:20:20','U11.SI',80,17.8300),(29,9,0,'2016-08-11 04:21:00','ME8U.SI',400,1.7650),(30,9,0,'2016-08-11 04:21:18','ME8U.SI',300,1.7650),(31,9,0,'2016-08-11 04:21:42','U11.SI',10,17.8300),(32,11,0,'2016-08-11 09:39:00','AAPL',100,108.0000),(33,9,1,'2016-08-11 15:01:12','U11.SI',90,17.8700),(34,9,0,'2016-08-11 15:02:22','AAPL',5,108.5150),(35,9,0,'2016-08-11 15:04:29','U11.SI',50,17.8700),(36,9,1,'2016-08-11 15:11:06','U11.SI',50,17.8700),(37,9,1,'2016-08-11 15:11:15','ME8U.SI',800,1.7750),(38,9,0,'2016-08-11 15:11:55','AAPL',3,108.3340),(39,9,0,'2016-08-11 15:12:19','BABA',1,91.8701),(40,9,0,'2016-08-11 15:12:45','FB',5,125.1069),(41,9,0,'2016-08-11 15:13:29','YHOO',18,41.3400),(42,9,0,'2016-08-11 15:14:37','U11.SI',46,17.8700),(43,11,1,'2016-08-11 15:16:19','AAPL',400,108.4500),(44,11,0,'2016-08-11 15:16:27','AAPL',200,108.4520);
/*!40000 ALTER TABLE `history` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `portfolios`
--

DROP TABLE IF EXISTS `portfolios`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `portfolios` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `user_id` int(5) unsigned NOT NULL,
  `symbol` char(8) NOT NULL,
  `shares` int(10) unsigned NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `user_id` (`user_id`,`symbol`)
) ENGINE=InnoDB AUTO_INCREMENT=30 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `portfolios`
--

LOCK TABLES `portfolios` WRITE;
/*!40000 ALTER TABLE `portfolios` DISABLE KEYS */;
INSERT INTO `portfolios` VALUES (10,9,'AAPL',18),(11,9,'BABA',21),(12,9,'FB',15),(13,9,'GOOG',2),(14,9,'YHOO',48),(28,9,'U11.SI',46),(29,11,'AAPL',200);
/*!40000 ALTER TABLE `portfolios` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `users`
--

DROP TABLE IF EXISTS `users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `users` (
  `id` int(5) unsigned NOT NULL AUTO_INCREMENT,
  `username` varchar(255) NOT NULL,
  `hash` varchar(255) NOT NULL,
  `cash` decimal(65,4) unsigned NOT NULL DEFAULT '0.0000',
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`)
) ENGINE=InnoDB AUTO_INCREMENT=64 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `users`
--

LOCK TABLES `users` WRITE;
/*!40000 ALTER TABLE `users` DISABLE KEYS */;
INSERT INTO `users` VALUES (1,'andi','$2y$10$c.e4DK7pVyLT.stmHxgAleWq4yViMmkwKz3x8XCo4b/u3r8g5OTnS',10000.0000),(2,'caesar','$2y$10$0p2dlmu6HnhzEMf9UaUIfuaQP7tFVDMxgFcVs0irhGqhOxt6hJFaa',10000.0000),(3,'eli','$2y$10$COO6EnTVrCPCEddZyWeEJeH9qPCwPkCS0jJpusNiru.XpRN6Jf7HW',10000.0000),(4,'hdan','$2y$10$o9a4ZoHqVkVHSno6j.k34.wC.qzgeQTBHiwa3rpnLq7j2PlPJHo1G',10000.0000),(5,'jason','$2y$10$ci2zwcWLJmSSqyhCnHKUF.AjoysFMvlIb1w4zfmCS7/WaOrmBnLNe',10000.0000),(6,'john','$2y$10$dy.LVhWgoxIQHAgfCStWietGdJCPjnNrxKNRs5twGcMrQvAPPIxSy',10000.0000),(7,'levatich','$2y$10$fBfk7L/QFiplffZdo6etM.096pt4Oyz2imLSp5s8HUAykdLXaz6MK',10000.0000),(8,'rob','$2y$10$3pRWcBbGdAdzdDiVVybKSeFq6C50g80zyPRAxcsh2t5UnwAkG.I.2',10000.0000),(9,'skroob','$2y$10$FcAtLPyp3QLDrXFcl3x7z.hfCsCQ7bvn7wW2tC/8W7J1M5PSf3ZWW',17.8184),(10,'zamyla','$2y$10$UOaRF0LGOaeHG4oaEkfO4O7vfI34B1W23WqHr9zCpXL68hfQsS3/e',10000.0000),(11,'JJLin','$2y$10$PWB6QCfQDjpHoIO1vi2XSu6Uwwf.DUhFuGrLGplMw2KQwaU7dLJuG',31089.6000);
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

-- Dump completed on 2016-08-11 16:58:01
