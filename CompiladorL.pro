TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11
SOURCES += main.cpp \
    Lexico.cpp \
    Sintactico.cpp \
    Token.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    ExcepcionLexica.h \
    ExcepcionSintactica.h \
    Lexico.h \
    NodoArchivoSecuencial.h \
    NodoCaso.h \
    NodoDeclaracion.h \
    NodoDeclaracionSubPrograma.h \
    NodoDiferente.h \
    NodoDivision.h \
    NodoDivisionEntera.h \
    NodoExponente.h \
    NodoExpression.h \
    NodoFalso.h \
    NodoFuncion.h \
    NodoFuncionEncabezado.h \
    NodoHtml.h \
    NodoId.h \
    NodoIgual.h \
    NodoListaLiteralEnteros.h \
    NodoLiteralCadena.h \
    NodoLiteralCaracter.h \
    NodoLiteralEntero.h \
    NodoLiteralReal.h \
    NodoLlamarFuncion.h \
    NodoMayor.h \
    NodoMayorIgual.h \
    NodoMenor.h \
    NodoMenorIgual.h \
    NodoModular.h \
    NodoMultiplicacion.h \
    NodoO.h \
    NodoOperacionBinaria.h \
    NodoOperacionLectura.h \
    NodoOperactionEscritura.h \
    NodoOperadorNo.h \
    NodoParametro.h \
    NodoParametroVar.h \
    NodoProcedimientoEncabezado.h \
    NodoPropAbrir.h \
    NodoPropAsignar.h \
    NodoPropCerrar.h \
    NodoPropEscriba.h \
    NodoPropEscribir.h \
    NodoPropLeer.h \
    NodoPropMientras.h \
    NodoProposicionCaso.h \
    NodoPropPara.h \
    NodoPropRepita.h \
    NodoPropSi.h \
    NodoRegistro.h \
    NodoResta.h \
    NodoRetorne.h \
    NodoSentencia.h \
    NodoSino.h \
    NodoSinoCaso.h \
    NodoSuma.h \
    NodoTipo.h \
    NodoTipoArchivo.h \
    NodoTipoCadena.h \
    NodoTipoObjecto.h \
    NodoTipoPrimitivoBooleano.h \
    NodoTipoPrimitivoCaracter.h \
    NodoTipoPrimitivoEntero.h \
    NodoTipoPrimitivoReal.h \
    NodoTipoVariableArreglo.h \
    NodoValorNegativo.h \
    NodoVariableArreglo.h \
    NodoVariableRegistro.h \
    NodoVerdadero.h \
    NodoY.h \
    Sintactico.h \
    Token.h \
    tipoentero.h \
    tiporeal.h \
    tipobooleano.h \
    tipocaracter.h \
    tipoarreglo.h \
    tipov.h \
    nodobasico.h \
    nodoarchivovariable.h \
    excepcionsemantica.h \
    tipocadena.h \
    tablasimbolos.h \
    datosfuncion.h \
    tipovoid.h \
    datosregistro.h \
    tipodatos.h \
    infofuncion.h \
    inforegistro.h \
    valorinterpretado.h \
    valorarreglo.h \
    valorbooleano.h \
    valorflotante.h \
    valorentero.h \
    valorcadena.h \
    valorcaracter.h \
    tablasimbolosinterpretado.h \
    datosfuncioninterpretado.h

DISTFILES += \
    lexico.txt

