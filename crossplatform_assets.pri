SOURCES += assetsmanager.cpp \
    $$PWD/dbmanager.cpp

HEADERS += assetsmanager.h \
    $$PWD/dbmanager.h

source = $$PWD/assets
target = $$OUT_PWD/assets
target ~= s,\\\\\\.?\\\\,\\,


win32{
    message("target is windows")
    if(exists($$OUT_PWD/assets)){
        message("assets exists!")
    }
    else{
        message("assets not exists!")
        source = $$replace(source, /, \\)
        target = $$replace(target, /, \\)
        target ~= s,\\\\\\.?\\\\,\\,
        copyCommand += xcopy /E /I /Y \"$$source\" \"$$target\"
        copydeploymentfolders.commands += $$copyCommand
        first.depends += $(first) copydeploymentfolders
        export(first.depends)
        export(copydeploymentfolders.commands)
        QMAKE_EXTRA_TARGETS += first copydeploymentfolders
    }
}
win64{
    message("target is windows")
    if(exists($$OUT_PWD/assets)){
        message("assets exists!")
    }
    else{
        message("assets not exists!")
        source = $$replace(source, /, \\)
        target = $$replace(target, /, \\)
        target ~= s,\\\\\\.?\\\\,\\,
        copyCommand += xcopy /E /I /Y \"$$source\" \"$$target\"
        copydeploymentfolders.commands += $$copyCommand
        first.depends += $(first) copydeploymentfolders
        export(first.depends)
        export(copydeploymentfolders.commands)
        QMAKE_EXTRA_TARGETS += first copydeploymentfolders
    }
}
android{
    QT += androidextras
    message("target is android")
    COMMON_DATA.path = /assets
    COMMON_DATA.files = $$files($$PWD/assets/*)
    INSTALLS += COMMON_DATA
}
mac {
    QT += macextras
}
