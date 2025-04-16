package com.example.myapplication;

import android.graphics.Bitmap;
import android.os.Bundle;
import android.webkit.WebSettings;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;
import java.io.File;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);

        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });

        WebView webView = findViewById(R.id.webView);
        WebSettings webSettings = webView.getSettings();
        webSettings.setJavaScriptEnabled(true);

        webView.setWebViewClient(new WebViewClient() {
            @Override
            public void onPageFinished(WebView view, String url) {
                super.onPageFinished(view, url);
                
                String faviconUrl = "file:///App/Android/assets/logodb.png";

                String jsCode = "var link = document.querySelector(\"link[rel='icon']\") || document.createElement(\"link\");" +
                                "link.rel = 'icon';" +
                                "link.href = '" + faviconUrl + "';" +
                                "document.head.appendChild(link);";

                view.evaluateJavascript(jsCode, null);
            }
        });

        webView.loadUrl("https://librarydb.netlify.app");
    }
}


// Path: App/Android/res/layout/activity_main.xml
// Using Android Studio / Java / XML , By : Saad Almalki