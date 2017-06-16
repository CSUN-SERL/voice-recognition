# This module defines

#JVM_FOUND
#JVM_LIBRARY
#JVM_DEFINITIONS
#JVM_INCLUDE_DIRS


MACRO( FIND_JVM_INCLUDE THIS_JVM_INCLUDE_DIR THIS_JVM_INCLUDE_FILE)
    FIND_PATH( ${THIS_JVM_INCLUDE_DIR}
        NAMES
            "${THIS_JVM_INCLUDE_FILE}"
        PATHS
            ${JVM_DIR}
            $ENV{JVM_DIR}
            /usr/lib/jvm
            /usr/lib/jvm/java-6-openjdk-amd64
            /usr/lib/jvm/java-7-openjdk-amd64
            /usr/lib/jvm/java-8-openjdk-amd64
            /usr/lib/jvm/java-6-openjdk-i386
            /usr/lib/jvm/java-7-openjdk-i386
            /usr/lib/jvm/java-8-openjdk-i386
        PATH_SUFFIXES
            /include/
            /include/linux/
)

ENDMACRO( FIND_JVM_INCLUDE THIS_JVM_INCLUDE_DIR THIS_JVM_INCLUDE_FILE)


FIND_JVM_INCLUDE( JVM_INCLUDE_DIR_jni    jni.h)

message("000000000000000000000000000000000")
message("${JVM_INCLUDE_DIR_jni}")


FIND_JVM_INCLUDE( JVM_INCLUDE_DIR_jni_md    jni_md.h)

message("000000000000000000000000000000000")
message("${JVM_INCLUDE_DIR_jni_md}")

MACRO( FIND_VOCE_INCLUDE THIS_VOCE_INCLUDE_DIR THIS_VOCE_INCLUDE_FILE)
    FIND_PATH( ${THIS_VOCE_INCLUDE_DIR}
        NAMES
            "${THIS_VOCE_INCLUDE_FILE}"
        PATHS
            ${VOCE_DIR}
            $ENV{VOCE_DIR}
            /usr/lib
            /usr/local/lib
        PATH_SUFFIXES
            /src/c++/
)

ENDMACRO( FIND_VOCE_INCLUDE THIS_VOCE_INCLUDE_DIR THIS_VOCE_INCLUDE_FILE)

FIND_VOCE_INCLUDE( JVM_INCLUDE_DIR_voce    voce.h)

message("000000000000000000000000000000000")
message("${JVM_INCLUDE_DIR_voce}")


MACRO ( FIND_JVM_LIBRARY MYLIBRARY JVM_LIBRARY)

FIND_LIBRARY(${MYLIBRARY}
    NAMES
        ${JVM_LIBRARY}
    PATHS
        ${JVM_DIR}
        $ENV{JVM_DIR}
        /usr/lib/jvm
        /usr/lib/jvm/java-6-openjdk-amd64/jre/lib
        /usr/lib/jvm/java-7-openjdk-amd64/jre/lib
        /usr/lib/jvm/java-8-openjdk-amd64/jre/lib
        /usr/lib/jvm/java-6-openjdk-i386/jre/lib
        /usr/lib/jvm/java-7-openjdk-i386/jre/lib
        /usr/lib/jvm/java-8-openjdk-i386/jre/lib
    PATH_SUFFIXES
        /amd64/server/
        /i386/server/
     )

ENDMACRO ( FIND_JVM_LIBRARY MYLIBRARY JVM_LIBRARY)

FIND_JVM_LIBRARY (JVM_LIBRARY  jvm)



SET( JVM_FOUND "NO" )
IF( JVM_LIBRARY AND JVM_INCLUDE_DIR_jni AND JVM_INCLUDE_DIR_jni_md AND JVM_INCLUDE_DIR_voce )
    SET( JVM_FOUND "YES" )
    SET( JVM_INCLUDE_DIRS "${JVM_INCLUDE_DIR_jni};${JVM_INCLUDE_DIR_jni_md};${JVM_INCLUDE_DIR_voce}")
    SET( JVM_DEFINITIONS "")
ENDIF( JVM_LIBRARY AND JVM_INCLUDE_DIR_jni AND JVM_INCLUDE_DIR_jni_md AND JVM_INCLUDE_DIR_voce )

