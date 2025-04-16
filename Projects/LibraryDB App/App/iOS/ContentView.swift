import SwiftUI
import WebKit

struct WebView: UIViewRepresentable {
    let url: String

    func makeUIView(context: Context) -> WKWebView {
        let webView = WKWebView()
        if let requestUrl = URL(string: url) {
            webView.load(URLRequest(url: requestUrl))
        }
        return webView
    }

    func updateUIView(_ webView: WKWebView, context: Context) {
    }
}

struct ContentView: View {
    var body: some View {
        VStack {
            WebView(url: "https://librarydb.netlify.app")
                .frame(height: 400)
                .edgesIgnoringSafeArea(.top)

            Spacer()

            if let imagePath = Bundle.main.path(forResource: "logodb", ofType: "png"),
               let uiImage = UIImage(contentsOfFile: imagePath) {
                Image(uiImage: uiImage)
                    .resizable()
                    .scaledToFit()
                    .frame(height: 200)
                    .padding()
            } else {
                Text("not found logodb.png")
                    .foregroundColor(.red)
            }
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}

// Using Xcode - Swift , Project by : Saad Almalki
