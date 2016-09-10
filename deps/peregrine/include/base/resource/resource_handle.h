// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BASE_RESOURCE_RESOURCE_HANDLE_H_
#define BASE_RESOURCE_RESOURCE_HANDLE_H_

#include "base/basictypes.h"
#include "base/strings/string_piece.h"

#include "base/base_export.h"

namespace base {
class RefCountedStaticMemory;
}

namespace base {

class BASE_EXPORT ResourceHandle {
 public:
  // What type of encoding the text resources use.
  enum TextEncodingType {
    BINARY,
    UTF8,
    UTF16
  };

  virtual ~ResourceHandle() {}

  // Returns true if the DataPack contains a resource with id |resource_id|.
  virtual bool HasResource(uint16 resource_id) const = 0;

  // Get resource by id |resource_id|, filling in |data|.
  // The data is owned by the DataPack object and should not be modified.
  // Returns false if the resource id isn't found.
  virtual bool GetStringPiece(uint16 resource_id,
                              base::StringPiece* data) const = 0;

  // Like GetStringPiece(), but returns a reference to memory.
  // Caller owns the returned object.
  virtual base::RefCountedStaticMemory* GetStaticMemory(
      uint16 resource_id) const = 0;

  // Get the encoding type of text resources.
  virtual TextEncodingType GetTextEncodingType() const = 0;

};

}  // namespace base

#endif  // BASE_RESOURCE_RESOURCE_HANDLE_H_