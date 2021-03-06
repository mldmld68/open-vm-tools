/*
 *  Author: bwilliams
 *  Created: April 6, 2012
 *
 *  Copyright (C) 2012-2016 VMware, Inc.  All rights reserved. -- VMware Confidential
 *
 *  This code was generated by the script "build/dev/codeGen/genCppXml". Please
 *  speak to Brian W. before modifying it by hand.
 *
 */

#include "stdafx.h"

#include "Doc/DocXml/CafCoreTypesXml/RequestXml.h"
#include "Doc/DocXml/MultiPmeMgmtRequestXml/MultiPmeMgmtRequestXml.h"

#include "Doc/MultiPmeMgmtRequestDoc/CMultiPmeMgmtRequestDoc.h"
#include "Xml/XmlUtils/CXmlElement.h"
#include "Doc/DocXml/MultiPmeMgmtRequestXml/MultiPmeMgmtRequestXmlRoots.h"

using namespace Caf;

std::string XmlRoots::saveMultiPmeMgmtRequestToString(
	const SmartPtrCMultiPmeMgmtRequestDoc multiPmeMgmtRequestDoc) {
	CAF_CM_STATIC_FUNC_VALIDATE("XmlRoots", "saveMultiPmeMgmtRequestToString");

	std::string rc;

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(multiPmeMgmtRequestDoc);

		const std::string schemaNamespace = DocXmlUtils::getSchemaNamespace("fx");
		const std::string schemaLocation = DocXmlUtils::getSchemaLocation("fx/MultiPmeMgmtRequest.xsd");

		const SmartPtrCXmlElement rootXml = CXmlUtils::createRootElement(
			"multiPmeMgmtRequest", schemaNamespace, schemaLocation);
		MultiPmeMgmtRequestXml::add(multiPmeMgmtRequestDoc, rootXml);

		rc = rootXml->saveToString();
	}
	CAF_CM_EXIT;

	return rc;
}

SmartPtrCMultiPmeMgmtRequestDoc XmlRoots::parseMultiPmeMgmtRequestFromString(
	const std::string xml) {
	CAF_CM_STATIC_FUNC_VALIDATE("XmlRoots", "parseMultiPmeMgmtRequestFromString");

	SmartPtrCMultiPmeMgmtRequestDoc multiPmeMgmtRequestDoc;

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_STRING(xml);

		const SmartPtrCXmlElement rootXml = RequestXml::parseString(xml, "caf:multiPmeMgmtRequest");
		multiPmeMgmtRequestDoc = MultiPmeMgmtRequestXml::parse(rootXml);
	}
	CAF_CM_EXIT;

	return multiPmeMgmtRequestDoc;
}

void XmlRoots::saveMultiPmeMgmtRequestToFile(
	const SmartPtrCMultiPmeMgmtRequestDoc multiPmeMgmtRequestDoc,
	const std::string filePath) {
	CAF_CM_STATIC_FUNC_LOG_VALIDATE("XmlRoots", "saveMultiPmeMgmtRequestToFile");

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(multiPmeMgmtRequestDoc);
		CAF_CM_VALIDATE_STRING(filePath);

		CAF_CM_LOG_DEBUG_VA1("Saving to file - %s", filePath.c_str());

		const std::string multiPmeMgmtRequestStr =
			saveMultiPmeMgmtRequestToString(multiPmeMgmtRequestDoc);
		FileSystemUtils::saveTextFile(filePath, multiPmeMgmtRequestStr);
	}
	CAF_CM_EXIT;
}

SmartPtrCMultiPmeMgmtRequestDoc XmlRoots::parseMultiPmeMgmtRequestFromFile(
	const std::string filePath) {
	CAF_CM_STATIC_FUNC_VALIDATE("XmlRoots", "parseMultiPmeMgmtRequestFromFile");

	SmartPtrCMultiPmeMgmtRequestDoc multiPmeMgmtRequestDoc;

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_STRING(filePath);

		const SmartPtrCXmlElement rootXml = RequestXml::parseFile(filePath, "caf:multiPmeMgmtRequest");
		multiPmeMgmtRequestDoc = MultiPmeMgmtRequestXml::parse(rootXml);
	}
	CAF_CM_EXIT;

	return multiPmeMgmtRequestDoc;
}
