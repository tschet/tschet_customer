# Tschet Customer for Drupal 7

CONTENTS OF THIS FILE
---
 * Introduction
 * Installation
 * Field Descriptions
 * Current Maintainers

Introduction
---
This module adds a Customer node type with assocaited fields. Fields will be 
described below. It adds Customer page to the menu, and displays all Customer
nodes in node post date order.
The Customer page displays nodes as Teasers. This will allow for modules such as
[Display Suite](https://www.drupal.org/project/ds) to easily change the display 
by modifying the Teaser. It could also be replaced by Views using the Fields, 
the Teaser view mode, or anything else that was desired. 

Installation
---
Install as you would normally install a contributed Drupal module. See: 
https://drupal.org/documentation/install/modules-themes/modules-7 
for further information.

It has six module dependencies
 
 * [Date](https://www.drupal.org/project/date)
 * [email](https://www.drupal.org/project/email)
 * [location](https://www.drupal.org/project/location)
 * [location_cck](https://www.drupal.org/project/location)
 * [name](https://www.drupal.org/project/name)
 * [phone](https://www.drupal.org/project/phone)

Description
---
The Tschet Customer moodule uses five custom fields.

Customer Name
A Name field, allowing for entry of separate values for title,
Given name, Middle name, Family name, Generational value, and Credentials. This 
allows for a wide range of display options and sorting. This field is being 
used to generate the Node Title value using hook_node_presave. The default node 
title field is disabled by use of a hook_form_BASE_FORM_ID_alter.

Date of Birth
A Date field, collecting a single date value of Year, Month, Day. This is 
displayed in a custom date format installed with hook_date_format_types. The 
format is also added with variable_set so that the Date format is immediately 
available.

Address
A Location CCK field collectign a single address. The field collects locaiton 
name, address, additional address line, city, state, ZIP, and country. 
Longitude and Latitude are disabled since mapping was not planned for at this 
time. That feature could easily be added later. Location Email and Phone modules 
were not used as they do not validate well, and those values are often used 
outside the scope of the address field. I also add a custom location.tpl.php
using hook_theme_registry_alter for the address display, as the default 
template displays addresses in a non-conventional format.

Customer Email
An Email field with full validation and display options. Collects a single email 
value.

Customer Phone
An Phone field with full validation and display options. Collects a single phone  
number. Currently validates numbers based on USA and Canada number formats, but 
other formats are available.

Current Maintainers
---
 * Douglas Tschetter (tschet) - https://www.drupal.org/u/tschet
 
