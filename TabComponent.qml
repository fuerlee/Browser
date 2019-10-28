...
TextInput {
    onAccepted: {
        var result = siteLoader.loadSite(addressIpt.text)
        if (result === LoadResultType.SUCCESS) {
            var props = siteLoader.loadProperties(addressIpt.text)
            var qmlPath = siteLoader.getMainQmlPath(addressIpt.text)
            pageLoader.setSource(qmlPath, props)
        } else {
            ...
        }
    }
}
...
Loader {
    id: pageLoader
}