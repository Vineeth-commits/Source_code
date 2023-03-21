//===----------------------------------------------------------------------===//
//
// This source file is part of the Swift Collections open source project
//
// Copyright (c) 2022 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See https://swift.org/LICENSE.txt for license information
//
//===----------------------------------------------------------------------===//

import _CollectionsUtilities

extension TreeSet: CustomStringConvertible {
  /// A textual representation of this instance.
  public var description: String {
    _arrayDescription(for: self)
  }
}

extension TreeSet: CustomDebugStringConvertible {
  /// A textual representation of this instance, suitable for debugging.
  public var debugDescription: String {
    _arrayDescription(
      for: self, debug: true, typeName: _debugTypeName())
  }

  internal func _debugTypeName() -> String {
    "TreeSet<\(Element.self)>"
  }
}
