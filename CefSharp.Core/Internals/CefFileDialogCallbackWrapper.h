// Copyright � 2010-2015 The CefSharp Authors. All rights reserved.
//
// Use of this source code is governed by a BSD-style license that can be found in the LICENSE file.

#pragma once

#include "Stdafx.h"

#include "include\cef_dialog_handler.h"

namespace CefSharp
{
    public ref class CefFileDialogCallbackWrapper : IFileDialogCallback
    {
    private:
        MCefRefPtr<CefFileDialogCallback> _callback;
        bool _disposed;

    public:
        CefFileDialogCallbackWrapper(CefRefPtr<CefFileDialogCallback> &callback) :
            _callback(callback),
            _disposed(false)

        {
            
        }

        !CefFileDialogCallbackWrapper()
        {
            _callback = NULL;
        }

        ~CefFileDialogCallbackWrapper()
        {
            this->!CefFileDialogCallbackWrapper();

            _disposed = true;
        }

        virtual void Continue(int selectedAcceptFilter, List<String^>^ filePaths)
        {
            _callback->Continue(selectedAcceptFilter, StringUtils::ToNative(filePaths));

            delete this;
        }
        
        virtual void Cancel()
        {
            _callback->Cancel();

            delete this;
        }

        virtual property bool IsDisposed
        {
            bool get()
            {
                return _disposed;
            }
        }
    };
}

