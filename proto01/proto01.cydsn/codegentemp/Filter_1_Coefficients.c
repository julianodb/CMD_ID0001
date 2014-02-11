#include "Filter_1.h"
#include "Filter_1_PVT.h"


/*******************************************************************************
* ChannelA filter coefficients.
* Filter Type is: Biquad
*******************************************************************************/

/* Renamed array for backward compatibility.
*  Should not be used in new designs.
*/
#define ChannelABiquadCoefficients Filter_1_ChannelABiquadCoefficients

/* Number of Biquad sections are: 6 */

const uint8 CYCODE Filter_1_ChannelABiquadCoefficients[Filter_1_BIQUAD_A_SIZE] = 
{
 /* Coefficients of Section 0 */
 0xAAu, 0xFEu, 0x0Fu, 0x00u, /* Section(0)_A0, 0.249918460845947 */

 0xADu, 0x02u, 0xE0u, 0x00u, /* Section(0)_A1, -0.499836683273315 */

 0xAAu, 0xFEu, 0x0Fu, 0x00u, /* Section(0)_A2, 0.249918460845947 */

 0x4Eu, 0xF5u, 0x7Fu, 0x00u, /* Section(0)_B1, -1.99934720993042 */

 0xB2u, 0x0Au, 0xC0u, 0x00u, /* Section(0)_B2, 0.99934720993042 */

 /* Coefficients of Section 1 */
 0xB1u, 0xF9u, 0x3Fu, 0x00u, /* Section(1)_A0, 0.999614953994751 */

 0x9Eu, 0x0Cu, 0x80u, 0x00u, /* Section(1)_A1, -1.9992299079895 */

 0xB1u, 0xF9u, 0x3Fu, 0x00u, /* Section(1)_A2, 0.999614953994751 */

 0x62u, 0xF3u, 0x7Fu, 0x00u, /* Section(1)_B1, -1.9992299079895 */

 0x9Du, 0x0Cu, 0xC0u, 0x00u, /* Section(1)_B2, 0.999230146408081 */

 /* Coefficients of Section 2 */
 0x6Du, 0xFCu, 0x3Fu, 0x00u, /* Section(2)_A0, 0.999781847000122 */

 0x26u, 0x07u, 0x80u, 0x00u, /* Section(2)_A1, -1.99956369400024 */

 0x6Du, 0xFCu, 0x3Fu, 0x00u, /* Section(2)_A2, 0.999781847000122 */

 0xDAu, 0xF8u, 0x7Fu, 0x00u, /* Section(2)_B1, -1.99956369400024 */

 0x25u, 0x07u, 0xC0u, 0x00u, /* Section(2)_B2, 0.999563932418823 */

 /* Coefficients of Section 3 */
 0x61u, 0x61u, 0x3Fu, 0x00u, /* Section(3)_A0, 0.990318536758423 */

 0x3Du, 0x3Du, 0x81u, 0x00u, /* Section(3)_A1, -1.98063731193542 */

 0x61u, 0x61u, 0x3Fu, 0x00u, /* Section(3)_A2, 0.990318536758423 */

 0x7Du, 0xFDu, 0x7Fu, 0x00u, /* Section(3)_B1, -1.99984669685364 */

 0x83u, 0x02u, 0xC0u, 0x00u, /* Section(3)_B2, 0.999846696853638 */

 /* Coefficients of Section 4 */
 0xD0u, 0x26u, 0x00u, 0x00u, /* Section(4)_A0, 0.00236892700195313 */

 0xA0u, 0x4Du, 0x00u, 0x00u, /* Section(4)_A1, 0.00473785400390625 */

 0xD0u, 0x26u, 0x00u, 0x00u, /* Section(4)_A2, 0.00236892700195313 */

 0x32u, 0xA4u, 0x79u, 0x00u, /* Section(4)_B1, -1.90064668655396 */

 0x73u, 0x82u, 0xC5u, 0x00u, /* Section(4)_B2, 0.913913011550903 */

 /* Coefficients of Section 5 */
 0xD8u, 0x1Eu, 0x01u, 0x00u, /* Section(5)_A0, 0.0175075531005859 */

 0xB1u, 0x3Du, 0x02u, 0x00u, /* Section(5)_A1, 0.035015344619751 */

 0xD8u, 0x1Eu, 0x01u, 0x00u, /* Section(5)_A2, 0.0175075531005859 */

 0x60u, 0xA9u, 0x72u, 0x00u, /* Section(5)_B1, -1.79158782958984 */

 0xBEu, 0x89u, 0xCCu, 0x00u, /* Section(5)_B2, 0.804092884063721 */
};

