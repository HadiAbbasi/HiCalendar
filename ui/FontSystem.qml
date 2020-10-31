import QtQuick 2.15

Item {

    property var getContentFont: contentFont
    property var getContentFontLightFarsi: contentFontLightFarsi
    property var getContentFontLight: contentFontLight
    property var getContentFontFarsi: contentFontFarsi
    property var getAwesomeRegular: fontAwesomeRegular
    property var getAwesomeSolid: fontAwesomeSolid
    property var getAwesomeBrand: fontAwesomeBrand

    FontLoader {
        id: fontAwesomeBrand
        source: "qrc:/assets/Font Awesome 5 Brands-Regular-400.otf"
    }

    FontLoader {
        id: fontAwesomeRegular
        source: "qrc:/assets/Font Awesome 5 Free-Regular-400.otf"
    }

    FontLoader {
        id: fontAwesomeSolid
        source: "qrc:/assets/Font Awesome 5 Free-Solid-900.otf"
    }

    FontLoader {
        id: contentFont
        source: "qrc:/assets/Shabnam-Medium.ttf"
    }

    FontLoader {
        id: contentFontLight
        source: "qrc:/assets/Shabnam-Light.ttf"
    }

    FontLoader {
        id: contentFontLightFarsi
        source: "qrc:/assets/Shabnam-Light-FD.ttf"
    }

    FontLoader {
        id: contentFontFarsi
        source: "qrc:/assets/Shabnam-Medium-FD.ttf"
    }
}
