#include "stdafx.h"  
#include "dcmtk/dcmdata/dctk.h"  
#include "dcmtk/dcmimgle/dcmimage.h"  
#include "dcmtk/dcmdata/dcfilefo.h"  

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	DcmFileFormat fileformat;
	OFCondition oc = fileformat.loadFile("111.dcm");
	if (oc.good()){
		OFString patientName;
		if (fileformat.getDataset()->findAndGetOFString(DCM_PatientName, patientName).good())
		{
			cout << "Patient Name:" << patientName.data();
		}
	}
	return 0;
}